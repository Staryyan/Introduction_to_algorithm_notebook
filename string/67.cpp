class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size();
        int maxSize = max(aLen, bLen);
        string ans(maxSize + 1, '0');
        if (aLen > bLen) {
            int diff = aLen - bLen;
            string zeros(diff, '0');
            b = zeros + b;
        } else {
            int diff = bLen - aLen;
            string zeros(diff, '0');
            a = zeros + a;
        }
        int total = 0;
        for (int i = maxSize - 1; i >= 0; --i) {
            total = a[i] - '0' + b[i] - '0' + ans[i + 1] - '0';
            if (total >= 2) {
                ans[i] = '1';
                ans[i + 1] = total - 2 + '0';
            } else {
                ans[i + 1] = total + '0';
            }
        }
        if (ans[0] == '0') {
            ans = ans.substr(1);
        }
        return ans;
    }
};