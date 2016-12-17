/**
 * High accuracy multiply.
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        unsigned int len1 = num1.length(), len2 = num2.length();
        if (len1 == 0 || len2 == 0) { return "0"; }
        vector<int> ans(len1 + len2, 0);
        for (unsigned int i = 0; i < len1; ++i) {
            int num = num1[len1 - i - 1] - '0';
            int carry = 0;
            for (int j = 0; j < len2; ++j) {
                int sum = num * (num2[len2 - j - 1] - '0') + ans[i + j] + carry;
                carry = sum / 10;
                ans[i + j] = sum % 10;
            }
            ans[i + len2] += carry;
        }
        int start = len1 + len2 - 1;
        while (ans[start] == 0) { start--; }
        string s = "";
        for (int k = start; k >= 0; --k) {
            s += '0' + ans[k];
        }
        return s == "" ? "0" : s;
    }
};