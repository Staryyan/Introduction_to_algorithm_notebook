class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int idx = 0; 0 < strs.size(); prefix += strs[0][idx], ++idx) {
            for (int index = 0; index < strs.size(); ++index) {
                if (idx >= strs[index].size() || (index > 0 && strs[index][idx] != strs[index - 1][idx])) {
                    return prefix;
                }
            }
        }
        return prefix;
    }
};