/**
 * KMP.
 */
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1, k = 0, len = (int)str.size();
        vector<int> prefix(len + 1, 0);
        while (i < len) {
            if (str[i] == str[k]) {
                prefix[++i] = ++k;
            } else if (k == 0) {
                i++;
            } else {
                k = prefix[k];
            }
        }
        return prefix[len] && prefix[len] % (len - prefix[len]) == 0;
    }
};