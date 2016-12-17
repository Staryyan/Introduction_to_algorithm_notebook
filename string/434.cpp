class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0) { return 0; }
        int count = 0;
        bool existed = false;
        for (int i = 0; i < s.size(); ++i) {
            if (existed && s[i] == ' ') {
                count++;
                existed = false;
            } else if (s[i] != ' ') {
                existed = true;
            }
        }
        return existed ? count + 1 : count;
    }
};