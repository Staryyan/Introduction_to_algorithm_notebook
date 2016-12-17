class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (int i = 0; i < magazine.size(); ++i) {
            hash[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); ++j) {
            hash[ransomNote[j] - 'a']--;
            if (hash[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};