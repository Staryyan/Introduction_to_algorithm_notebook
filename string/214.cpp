#include "init.h"
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        int maxCen = 0, maxLen = 0;
        for (int start = 0; start < len; ) {
            int left = start, right = start;
            while (right < len - 1 && s[right + 1] == s[right]) {
                right++;
            }
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            if (left == 0) {
                if (maxLen < right - left + 1) {
                    maxLen = right - left + 1;
                    maxCen = right;
                }
            }
        }
        string ans = s;
        for (int i = maxCen + 1; i < len; ++i) {
            ans = s[i] + ans;
        }
        return ans;
    }
};
int main() {
    cout << Solution().shortestPalindrome("abb") << endl;
    return 0;
}
/**
 * KMP.
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());
        string l = s + "#" + revS;
        vector<int> prefix(l.length(), 0);
        prefix[0] = -1;
        int index = -1;
        for (int i = 1; i < l.length(); ++i) {
            while (index > -1 && l[i] != l[index + 1]) {
                index = prefix[index];
            }
            if (l[i] == l[index + 1]) {
                index++;
            }
            prefix[i] = index;
        }
        return revS.substr(0, s.length() - prefix[l.length() - 1] - 1) + s;
    }
};