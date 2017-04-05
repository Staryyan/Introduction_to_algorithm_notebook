class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> hash;
        string tmp;
        for (int i = 0; i < words.size(); ++i) {
            tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            hash[tmp] = i;
        }
        if (hash.find("") != hash.end()) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == "") { continue; }
                if (ispalindrome(words[i])) {
                    ans.push_back({hash[""], i});
                }
            }
        }
        string left, right;
        for (int j = 0; j < words.size(); ++j) {
            for (int i = 0; i < words[j].length(); ++i) {
                left = words[j].substr(0, i);
                right = words[j].substr(i, words[j].length() - i);
                if (hash.find(right) != hash.end() && ispalindrome(left) && hash[right] != j) {
                    ans.push_back({hash[right], j});
                }
                if (hash.find(left) != hash.end() && ispalindrome(right) && hash[left] != j) {
                    ans.push_back({j, hash[left]});
                }
            }
        }
        return ans;
    }
    bool ispalindrome(string str) {
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str[i++] != str[j--]) { return false; }
        }
        return true;
    }
};