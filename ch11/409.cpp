class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> hash;
        for (auto each : s) {
            if (hash.find(each) != hash.end()) {
                hash[each]++;
            } else {
                hash.insert({each, 1});
            }
        }
        int count = 0;
        bool odd = false;
        for (auto each : hash) {
            if (each.second % 2 == 1) {
                odd = true;
            }
            count += each.second == 1 ? 0 : each.second % 2 ? each.second - 1 : each.second;
        }
        if (odd) {
            count++;
        }
        return count;
    }
};