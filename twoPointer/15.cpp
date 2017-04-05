class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int target, front, rear, sum;
        for (int i = 0; i < nums.size(); ++i) {
            target = -nums[i];
            front = i + 1;
            rear = (int)nums.size() - 1;
            while (front < rear) {
                sum = nums[front] + nums[rear];
                if (sum < target) {
                    front++;
                } else if (sum > target) {
                    rear--;
                } else {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[front];
                    tmp[2] = nums[rear];
                    ans.push_back(tmp);
                    while (front < rear && nums[front] == tmp[1]) { front++; }
                    while (front < rear && nums[rear] == tmp[2]) { rear--; }
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) { i++; }
        }
        return ans;
    }
};
