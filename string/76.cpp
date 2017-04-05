class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) { return ""; }
        int required[128] = {0};
        bool charSet[128] = {false};
        for (auto ch : t) {
            required[ch]++;
            charSet[ch] = true;
        }
        int i = -1, j = 0;
        int count = t.size();
        int maxLeft = 0, minLen = INT_MAX;
        while (i < (int)s.size() && j < (int)s.size()) {
            if (count) {
                i++;
                required[s[i]]--;
                if (charSet[s[i]] && required[s[i]] >= 0) { count--; }
            } else {
                if (minLen > i - j + 1) {
                    minLen = i - j + 1;
                    maxLeft = j;
                }
                required[s[j]]++;
                if (charSet[s[j]] && required[s[j]] > 0) {
                    count++;
                }
                j++;
            }
        }
        if (minLen == INT_MAX) { return ""; }
        return s.substr(maxLeft, minLen);
    }
};