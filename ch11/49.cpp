class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> count;
        int i = 0;
        for (auto each : strs) {
            sort(each.begin(), each.end());
            count[each].push_back(strs[i++]);
        }
        vector<vector<string>> ans;
        for (auto each : count) {
            ans.push_back(each.second);
        }
        return ans;
    }
};
