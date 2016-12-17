class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return false;
        }
        map<int, int> hash;
        k = min((int)nums.size(), k);
        for (int i = 0; i <= k; ++i) {
            if (hash[nums[i]] == 0) {
                hash[nums[i]]++;
            } else {
                return true;
            }
        }
        int right = k + 1;
        while (right < nums.size()) {
            hash[nums[right - k - 1]]--;
            if (hash[nums[right]] == 0) {
                hash[nums[right]]++;
            } else {
                return true;
            }
            right++;
        }
        return false;
    }
};