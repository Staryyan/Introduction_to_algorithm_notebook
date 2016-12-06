/**
 * 455
 * https://leetcode.com/problems/assign-cookies/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        auto comp = [](const int a, const int b) {
            return a < b;
        };
        sort(g.begin(), g.end(), comp);
        sort(s.begin(), s.end(), comp);
        int index = 0, count = 0;
        for (int i = 0; i < g.size(); ++i) {
            for (; index < s.size(); ++index) {
                if (s[index] >= g[i]) {
                    count++;
                    index++;
                    break;
                }
            }
        }
        return count;
    }
};
