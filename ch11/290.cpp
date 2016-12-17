class Solution {
private:
    vector<string> splite(string str) {
        string tmp;
        istringstream is(str);
        vector<string> ans;
        while (is) {
            is >> tmp;
            ans.push_back(tmp);
        }
        ans.pop_back();
        return ans;
    }
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mapPatternStr;
        map<string, char> mapStrPattern;
        vector<string> vec = splite(str);
        if (pattern.size() != vec.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); ++i) {
            if (mapPatternStr.find(pattern[i]) == mapPatternStr.end() && mapStrPattern.find(vec[i]) == mapStrPattern.end()) {
                mapPatternStr[pattern[i]] = vec[i];
                mapStrPattern[vec[i]] = pattern[i];
            } else {
                if (mapPatternStr[pattern[i]] != vec[i] || mapStrPattern[vec[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};