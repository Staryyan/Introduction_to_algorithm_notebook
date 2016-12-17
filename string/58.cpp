class Solution {
public:
    int lengthOfLastWord(string s) {
        int times = 0;
        bool blank = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                blank = true;
            } else {
                if (blank) {
                    times = 0;
                    blank = false;
                }
                times++;
            }
        }
        return times;
    }
};