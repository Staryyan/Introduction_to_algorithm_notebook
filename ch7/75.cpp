/**
 * Counter sort.
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans(3, 0);
        for (auto each : nums) {
            ans[each]++;
        }
        for (int i = 1; i < ans.size(); ++i) {
            ans[i] += ans[i - 1];
        }
        for (int j = 0; j < ans[0]; ++j) {
            nums[j] = 0;
        }
        for (int k = ans[0]; k < ans[1]; ++k) {
            nums[k] = 1;
        }
        for (int l = ans[1]; l < ans[2]; ++l) {
            nums[l] = 2;
        }
    }
};
int main() {
    vector<int> vec{2,1,1};
    Solution().sortColors(vec);
    for (auto each : vec) {
        cout << each << endl;
    }
}