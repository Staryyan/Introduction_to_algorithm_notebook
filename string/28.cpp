#include "init.h"
class Solution {
public:
    vector<int> constructPrefix(string pattern) {
        int len = pattern.size();
        vector<int> prefix(len, 0);
        prefix[0] = -1;
        int index = -1;
        for (int i = 1; i < len; ++i) {
            while (index > -1 && pattern[i] != pattern[index + 1]) {
                index = prefix[index];
            }
            if (pattern[i] == pattern[index + 1]) {
                index++;
            }
            prefix[i] = index;
        }
        return prefix;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) { return 0; }
        if (haystack.empty()) { return -1; }
        int len = haystack.size();
        vector<int> prefix = constructPrefix(needle);
        int index = -1;
        for (int i = 0; i < len; ++i) {
            while (index > -1 && haystack[i] != needle[index + 1]) {
                index = prefix[index];
            }
            if (haystack[i] == needle[index + 1]) {
                index++;
            }
            if (index == needle.size() - 1) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};
int main() {
    cout << Solution().strStr("mississippi", "issip") << endl;
    return 0;
}
