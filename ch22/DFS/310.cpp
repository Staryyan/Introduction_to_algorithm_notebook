class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> adj(n);
        for (auto edge : edges) {
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }
        if (n == 1) { return vector<int>{0}; }

        vector<int> current;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) { current.push_back(i); }
        }

        while (true) {
            vector<int> next;
            for (auto node : current) {
                for (auto neighbor : adj[node]) {
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1) {
                        next.push_back(neighbor);
                    }
                }
            }
            if (next.empty()) { return current; }
            current = next;
        }
    }
};