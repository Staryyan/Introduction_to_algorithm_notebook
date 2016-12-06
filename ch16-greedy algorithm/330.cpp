/**
 * TLE
 */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<int> map(n + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > n) { break; }
            for (int j = 1; j <= n; ++j) {
                if (map[j] == 1) {
                    if (j + nums[i] <= n) {
                        map[j + nums[i]] = 1;
                    } else {
                        break;
                    }
                }
            }
            map[nums[i]] = 1;
        }
        int count = 0;
        for (int k = 1; k <= n; ++k) {
            if (map[k] != 1) {
                count++;
                for (int i = 1; i <= n; ++i) {
                    if (map[i] == 1) {
                        if (i + k > n) {
                            break;
                        }
                        map[i + k] = 1;
                    }
                }
                map[k] = 1;
            }
        }
        return count;
    }
};

/**
 * https://discuss.leetcode.com/topic/45320/c-8ms-greedy-solution-with-explanation
 */
class Solution {
public:
    int minPatches(vector<int>& nums, long long n) {
        long long maxSum = 0;
        int index = 0, count = 0;
        while (maxSum < n) {
            if (index < nums.size() && nums[index] <= maxSum + 1) {
                maxSum += nums[index++];
            } else {
                maxSum += maxSum + 1; count++;
            }
        }
        return count;
    }
};
