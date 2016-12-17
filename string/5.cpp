class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxLeft = 0, maxLen = 0;
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
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                maxLeft = left;
            }
        }
        return s.substr(maxLeft, maxLen);
    }
};