class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        n--;
        while (n--) {
            string tmp = ans;
            ans = "";
            int times = 1;
            for (int i = 0; i < tmp.size() - 1; ++i) {
                if (tmp[i] == tmp[i + 1]) {
                    times++;
                } else {
                    ans += '0' + times;
                    ans += tmp[i];
                    times = 1;
                }
            }
            ans += '0' + times;
            ans += tmp[tmp.size() - 1];
        }
        return ans;
    }
};