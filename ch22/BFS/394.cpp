class Solution {
public:
    string decodeString(string s) {
        stack<char> charStack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ']') {
                string _str = "";
                while (charStack.top() != '[') {
                    _str = charStack.top() + _str;
                    charStack.pop();
                }
                string _copy = "";
                charStack.pop();
                string num = "";
                while (!charStack.empty() && isdigit(charStack.top()) == 1) {
                    num = charStack.top() + num;
                    charStack.pop();
                }
                int times = atoi(num.c_str());
                while (times--) { _copy += _str; }
                for (int j = 0; j < _copy.length(); ++j) { charStack.push(_copy[j]); }
            } else {
                charStack.push(s[i]);
            }
        }
        string ans;
        while (!charStack.empty()) {
            ans = charStack.top() + ans;
            charStack.pop();
        }
        return ans;
    }
};