#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int kth(vector<int>::iterator nums1, int n, vector<int>::iterator nums2, int m, int k) {
        if (n < m) { return kth(nums2, m, nums1, n, k); }
        if (m == 0) { return *(nums1 + k - 1); }
        if (k == 1) { return min(*nums1, *nums2); }
        int j = min(m, k / 2);
        int i = k - j;
        if (*(nums1 + i - 1) > *(nums2 + j - 1)) {
            return kth(nums1, i, nums2 + j, m - j, k - j);
        } else {
            return kth(nums1 + i, n - i, nums2, j, k - i);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int k = (m + n) / 2;
        int mid1 = kth(nums1.begin(), n, nums2.begin(), m, k + 1);
        if ((m + n) % 2 == 0) {
            int mid2 = kth(nums1.begin(), n, nums2.begin(), m, k);
            return (mid1 + mid2) / 2.0;
        } else {
            return mid1;
        }
    }
};

int main() {
    vector<int> vec1{1,2,3,4,5,6};
    vector<int> vec2{2,3,3,4,5,6,7,8,9,10};
    cout << Solution().findMedianSortedArrays(vec1, vec2) << endl;
}