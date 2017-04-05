class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> _stack;
        _stack.push(-1);
        int top;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            top = _stack.top();
            if (top != -1 && s[top] == '(' && s[i] == ')') {
                _stack.pop();
                maxLen = max(maxLen, i - _stack.top());
            } else {
                _stack.push(i);
            }
        }
        return maxLen;
    }
};