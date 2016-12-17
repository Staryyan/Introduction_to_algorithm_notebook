#include "init.h"
class Solution {
private:
    int merge(vector<long long>& sums, int start, int end, int lower, int upper){
        if (start >= end) { return 0; }
        int mid = start + ((end - start) >> 1);
        int count = merge(sums, start, mid, lower, upper) + merge(sums, mid + 1, end, lower, upper);
        vector<long long> tmp(end - start + 1, 0);
        int i = start, j = mid + 1, k = mid + 1, t = mid + 1, r = 0;
        for (; i <= mid; ++i) {
            while (j <= end && sums[j] - sums[i] <= upper) { j++; }
            while (k <= end && sums[k] - sums[i] < lower) { k++; }
            count += j - k;
            while (t <= end && sums[t] <= sums[i]) { tmp[r++] = sums[t++]; }
            tmp[r++] = sums[i];
        }
        for (int l = 0; l < r; ++l) {
            sums[l + start] = tmp[l];
        }
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) { return 0; }
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return merge(sums, 0, n, lower, upper);
    }
};

int main() {
    vector<int> vec{0,-3,-3,1,1,2};
    cout << Solution().countRangeSum(vec, 3, 5) << endl;
    return 0;
}