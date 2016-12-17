#include "init.h"
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) { return false; }
        bool tables[s1.length() + 1][s2.length() + 1];
        tables[0][0] = true;
        for (int i = 0; i < s1.length() + 1; ++i) {
            for (int j = 0; j < s2.length() + 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    tables[i][j] = (tables[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    tables[i][j] = (tables[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                } else {
                    tables[i][j] = (tables[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (tables[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return tables[s1.length()][s2.length()];
    }
};
int main() {
    cout << Solution().isInterleave("a", "b", "a") << endl;
    return 0;
}
