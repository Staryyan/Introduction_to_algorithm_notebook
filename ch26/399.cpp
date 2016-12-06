#define INF 100000
class Solution {
private:
    double check(string up, string down, unordered_map<string,unordered_map<string, double>> graph, unordered_set<string>& used) {
        if (graph[up].find(down) != graph[up].end()) { return graph[up][down]; }
        for (auto each : graph[up]) {
            if (used.find(each.first) == used.end()) {
                used.insert(each.first);
                double tmp = check(each.first, down, graph, used);
                if (tmp) { return tmp * each.second; }
            }
        }
        return 0;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string, double>> graph;
        for (int i = 0; i < values.size(); ++i) {
            graph[equations[i].first].insert({equations[i].second, values[i]});
            if (values[i] != 0) {
                graph[equations[i].second].insert({equations[i].first, 1 / values[i]});
            }
        }
        vector<double> answer;
        for (auto each : queries) {
            unordered_set<string> used;
            double tmp = check(each.first, each.second, graph, used);
            if (tmp) { answer.push_back(tmp); }
            else { answer.push_back(-1); }
        }
        return answer;
    }
};