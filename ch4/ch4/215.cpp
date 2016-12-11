/**
 * 基于快排的选数。
 */
class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
    int quickSelect(vector<int>& nums, int pos, int left, int right) {
        if (left <= right) {
            int mid = partition(nums, left, right);
            if (mid == pos) {
                return nums[mid];
            } else if (mid > pos) {
                return quickSelect(nums, pos, left, mid - 1);
            } else {
                return quickSelect(nums, pos, mid + 1, right);
            }
        }
        return -1;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos = nums.size() - k;
        return quickSelect(nums, pos, 0, nums.size() - 1);
    }
};