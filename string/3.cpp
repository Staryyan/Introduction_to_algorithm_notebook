class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash, -1, sizeof(hash));
        int start = -1, maxLen = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (hash[s[i]] > start) {
                start = hash[s[i]];
            }
            hash[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};