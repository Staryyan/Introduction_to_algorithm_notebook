#include "init.h"
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> hash;
        for (auto each : s) {
            if (hash.find(each) != hash.end()) {
                hash[each]++;
            } else {
                hash.insert({each, 1});
            }
        }
        vector<string> vec(s.size() + 1, "");
        for (auto each : hash) {
            vec[each.second].append(each.second, each.first);
        }
        string ans = "";
        for (int i = s.size(); i >= 0; --i) {
            if (vec[i] != "") {
                ans += vec[i];
            }
        }
        return ans;
    }
};

int main() {
    cout << Solution().frequencySort("tree") << endl;
}
