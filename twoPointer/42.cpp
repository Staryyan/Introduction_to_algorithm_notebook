#include "init.h"
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int ans = 0, maxLeft = INT_MIN, maxRight = INT_MIN;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    ans += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    ans += maxRight - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};