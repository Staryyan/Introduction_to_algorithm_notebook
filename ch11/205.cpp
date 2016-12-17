class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapST[128] = {0};
        int mapTS[128] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (mapST[s[i]] == 0 && mapTS[t[i]] == 0) {
                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            } else {
                if (mapST[s[i]] != t[i] || mapTS[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};