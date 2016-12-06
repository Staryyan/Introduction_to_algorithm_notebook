#include <stack>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) { return "0"; }
        stack<char> m_stack;
        for (int i = 0; i < num.size(); ++i) {
            if (m_stack.empty()) { m_stack.push(num[i]); }
            else {
                while (k > 0 && !m_stack.empty() && m_stack.top() > num[i]) {
                    m_stack.pop();
                    k--;
                }
                m_stack.push(num[i]);
            }
        }
        while (k != 0) {
            m_stack.pop();
            k--;
        }
        string ans;
        while (!m_stack.empty()) {
            ans = m_stack.top() + ans;
            m_stack.pop();
        }
        int index = 0;
        while (ans[index] == '0'){ index++; }
        if (index == ans.size()) {
            return  "0";
        } else {
            return ans.substr(index);
        }
    }
};