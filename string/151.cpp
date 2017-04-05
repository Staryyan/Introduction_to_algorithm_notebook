class Solution {
public:
    void reverseWords(string &s) {
        stack<string> _stack;
        string tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && tmp != "") {
                _stack.push(tmp);
                tmp = "";
            } else if (s[i] != ' ') {
                tmp += s[i];
            }
        }
        if (s[s.size() - 1] != ' ') { _stack.push(tmp); }
        s = "";
        if (!_stack.empty()) {
            s += _stack.top();
            _stack.pop();
        }
        while (!_stack.empty()) {
            s += " ";
            s += _stack.top();
            _stack.pop();
        }
    }
};