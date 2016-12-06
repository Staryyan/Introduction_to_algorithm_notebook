#include <stack>
#include <map>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> counts;
        map<char, bool> visited;
        for (auto each : s) {
            counts[each]++;
            visited[each] = false;
        }
        stack<char> str;
        for (auto each : s) {
            counts[each]--;
            if (visited[each]) { continue; }
            while (!str.empty() && each < str.top() && counts[str.top()]) {
                visited[str.top()] = false;
                str.pop();
            }
            str.push(each);
            visited[each] = true;
        }
        string ans;
        while (!str.empty()) {
            ans = str.top() + ans;
            str.pop();
        }
        return ans;
    }
};