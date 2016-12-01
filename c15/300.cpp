/**
 * 300
 * https://leetcode.com/problems/longest-increasing-subsequence/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /**
         * For each vertex,
         * the Longest Increasing Subsequence.
         */
        vector<int> lis(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        int maxSeq = 0;
        for (int k = 0; k < nums.size(); ++k) {
            maxSeq = max(maxSeq, lis[k]);
        }
        return maxSeq;
    }
};
