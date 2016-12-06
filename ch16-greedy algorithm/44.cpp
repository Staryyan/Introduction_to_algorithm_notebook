class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        vector<bool> prev(p_len + 1, false);
        prev[0] = true;
        for (int i = 1; i <= p_len; ++i) {
            prev[i] = prev[i - 1] && p[i - 1] == '*';
        }
        for (int j = 1; j <= s_len; ++j) {
            vector<bool> cur(p_len + 1, false);
            for (int i = 1; i <= p_len; ++i) {
                if (p[i - 1] == '*') {
                    cur[i] = cur[i - 1] || prev[i];
                } else {
                    cur[i] = prev[i - 1] && (p[i - 1] == s[j - 1] || p[i - 1] == '?');
                }
            }
            prev = cur;
        }
        return prev[p_len];
    }
};
/**
 * Greedy Algorithm
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        int sid = 0, pid = 0;
        int sidp = -1, pidp = -1;
        while (sid < s_len) {
            if (s[sid] == p[pid] || p[pid] == '?') {
                sid++; pid++;
            } else if (p[pid] == '*') {
                pidp = ++pid; sidp = sid;
            } else {
                if (pidp > -1) {
                    pid = pidp; sid = ++sidp;
                } else {
                    return false;
                }
            }
        }
        while (pid < p_len) {
            if (p[pid] != '*') {
                return false;
            }
            pid++;
        }
        return true;
    }
};
