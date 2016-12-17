class Solution {
private:
    typedef long long int i64;
    const char* s;
    i64 target;
    int slen;
    void processTail(i64 prevsum, i64 last, int pos, char* buf, int bufpos, vector<string>& res) {
        if (pos == slen) {
            if (prevsum + last == target) {
                buf[bufpos] = 0;
                res.push_back(buf);
            }
            return;
        }
        int lmax = (s[pos] == '0' ? 1 : slen - pos);
        i64 v = 0;
        for (int l = 1; l <= lmax; ++l) {
            int c = s[pos + l - 1];
            buf[bufpos + l] = c;
            v = v * 10 + (c - '0');

            buf[bufpos] = '+';
            processTail(prevsum + last, v, pos + l, buf, bufpos + l + 1, res);

            buf[bufpos] = '-';
            processTail(prevsum + last, -v, pos + l, buf, bufpos + l + 1, res);

            buf[bufpos] = '*';
            processTail(prevsum, last * v, pos + l, buf, bufpos + l + 1, res);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        this->target = target;
        slen = (int)num.size();
        s = num.c_str();
        int lmax = ((s[0] == '0') ? 1 : slen);
        char buf[2 * slen + 1];
        i64 v = 0;
        vector<string> res;
        for (int l = 1; l <= lmax; ++l) {
            int c = s[l - 1];
            buf[l - 1] = c;
            v = v * 10 + (c - '0');
            processTail(0, v, l, buf, l, res);
        }
        return res;
    }
};