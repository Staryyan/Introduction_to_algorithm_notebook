/**
 * https://leetcode.com/problems/jump-game/
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxStep = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (i <= maxStep) {
                maxStep = max(i + nums[i], maxStep);
            }
        }
        return maxStep >= nums.size() - 1;
    }
};
