#include "init.h"
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty()) {
            return 0;
        } else if (s.size() < t.size()) {
            return 0;
        }
        int sLen = s.size();
        int tLen = t.size();
        vector<vector<int>> table(sLen + 1, vector<int>(tLen + 1, 0));
        for (int k = 0; k < sLen; ++k) {
            table[k][0] = 1;
        }
        for (int i = 1; i <= sLen; ++i) {
            for (int j = 1; j <= tLen; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    /**
                     * 可以保留也可以删除。
                     */
                    table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
                } else {
                    /**
                     * 只能删除。
                     */
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        return table[sLen][tLen];
    }
};
int main() {
    cout << Solution().numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
