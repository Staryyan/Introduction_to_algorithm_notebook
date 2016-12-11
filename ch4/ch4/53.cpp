/**
 * 类似于DP思想。
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i = 0; i < input.size(); ++i) {
            char ch = input[i];
            if (ispunct(ch)) {
                for (auto k : diffWaysToCompute(input.substr(0, i))) {
                    for (auto j : diffWaysToCompute(input.substr(i + 1))) {
                        output.push_back(ch=='+' ? k+j : ch=='-' ? k-j : k*j);
                    }
                }
            }
        }
        return output.size() ? output : vector<int>{atoi(input.c_str())};
    }
};

int main() {
    string str = "1+1+1";
    Solution().diffWaysToCompute(str);
    return 0;
}
