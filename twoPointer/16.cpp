#include "init.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int pivot, front, rear, sum, ans = 10000;
        for (int i = 0; i < nums.size(); ++i) {
            pivot = nums[i];
            front = i + 1;
            rear = (int)nums.size() - 1;
            while (front < rear) {
                sum = pivot + nums[front] + nums[rear];
                ans = abs(sum - target) < abs(ans - target) ? sum : ans;
                if (sum < target) {
                    front++;
                } else if (sum > target) {
                    rear--;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};