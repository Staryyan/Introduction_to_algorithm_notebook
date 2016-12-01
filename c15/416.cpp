/**
 * 416
 * https://leetcode.com/problems/partition-equal-subset-sum/
 */
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    /**
     * If there is a sequence of num which can reach half,
     * then the left num can also construct a sequence which sums up as half.
     * @param nums 
     * @return 
     */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        /**
         * odd: false.
         */
        if (sum & 1) { return false; }
        int half = sum >> 1;
        vector<bool> accessibility(half + 1, false);
        accessibility[0] = true;
        for (auto num : nums) {
            for (int i = half; i >= num; --i) {
                if (accessibility[i - num]) {
                    accessibility[i] = true;
                }
            }
        }
        return accessibility[half];
    }
};
