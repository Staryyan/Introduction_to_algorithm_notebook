/**
 * 难点在于如何把比mid小的数放在奇数位，把比mid大的数放在偶数位。
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int n = nums.size();
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid) { swap(A(i++), A(j++)); }
            else if (A(j) < mid) { swap(A(j), A(k--)); }
            else {
                j++;
            }
        }
    }
};