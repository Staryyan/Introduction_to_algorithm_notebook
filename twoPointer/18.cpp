class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int globalTarget) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int localTarget, front, rear, sum;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                localTarget = globalTarget - (nums[i] + nums[j]);
                front = j + 1;
                rear = (int)nums.size() - 1;
                while (front < rear) {
                    sum = nums[front] + nums[rear];
                    if (sum < localTarget) {
                        front++;
                    } else if (sum > localTarget) {
                        rear--;
                    } else {
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[front];
                        tmp[3] = nums[rear];
                        ans.push_back(tmp);
                        while (front < rear && nums[front] == tmp[2]) {
                            front++;
                        }
                        while (front < rear && nums[rear] == tmp[3]) {
                            rear--;
                        }
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) { j++; }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) { i++; }
        }
        return ans;
    }
};