class Solution {
private:
    bool validate(string& s, int left, int right, map<char, int>& hashP, map<char, int>& hashS) {
        hashS[s[left - 1]]--;
        if (hashS[s[left - 1]] == 0) {
            hashS.erase(s[left - 1]);
        }
        hashS[s[right - 1]]++;
        return hashP == hashS;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return vector<int>{};
        }
        map<char, int> hashP;
        map<char, int> hashS;
        vector<int> ans;
        int len = p.size();
        for (auto each : p) {
            if (hashP.find(each) != hashP.end()) {
                hashP[each]++;
            } else {
                hashP.insert({each, 1});
            }
        }
        for (int j = 0; j < len; ++j) {
            if (hashS.find(s[j]) != hashS.end()) {
                hashS[s[j]]++;
            } else {
                hashS.insert({s[j], 1});
            }
        }
        if (hashS == hashP) { ans.push_back(0); }
        for (int i = 1; i < s.size() - len + 1; ++i) {
            if (validate(s, i, i + len, hashP, hashS)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
/**
 * better solution.
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.empty() || s.empty()) return ans;

        int cnt[256] = {0};
        for(char ch : p) cnt[ch] ++;

        int lf = 0, rt = 0;
        while(rt < s.size()) {
            cnt[s[rt]] --;
            while(lf <= rt && cnt[s[rt]] < 0) {
                cnt[s[lf ++]] ++;
            }
            if(rt - lf + 1 == p.size()) {
                ans.push_back(lf);
                cnt[s[lf ++]] ++;
            }
            rt ++;
        }
        return ans;
    }
};