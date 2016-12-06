class Solution {
private:
    map<string, priority_queue<string, vector<string>, greater<string>>> relations;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto each : tickets) {
            relations[each.first].push(each.second);
        }
        stack<string> searchStack;
        searchStack.push("JFK");
        vector<string> answer;
        while (!searchStack.empty()) {
            auto tmp = searchStack.top();
            if (relations[tmp].empty()) {
                answer.push_back(tmp);
                searchStack.pop();
            } else {
                searchStack.push(relations[tmp].top());
                relations[tmp].pop();
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};