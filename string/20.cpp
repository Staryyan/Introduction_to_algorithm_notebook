class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                charStack.push(s[i]);
            } else {
                if (s[i] == ')') {
                    if (charStack.empty() || charStack.top() != '(') {
                        return false;
                    } else {
                        charStack.pop();
                    }
                }
                if (s[i] == ']') {
                    if (charStack.empty() || charStack.top() != '[') {
                        return false;
                    } else {
                        charStack.pop();
                    }
                }
                if (s[i] == '}') {
                    if (charStack.empty() || charStack.top() != '{') {
                        return false;
                    } else {
                        charStack.pop();
                    }
                }
            }
        }
        return charStack.empty();
    }
};