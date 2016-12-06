using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int counts = 0;
        int maxStep = 0;
        while (maxStep < nums.size() - 1) {
            if (nums[maxStep] == 0) { return -1; }
            int localMax = 0;
            int index = -1;
            for (int i = 1; i <= nums[maxStep]; ++i) {
                if (maxStep + i >= nums.size() - 1) {
                    index = i;
                    break;
                }
                if (localMax < i + nums[i + maxStep]) {
                    localMax = i + nums[i + maxStep];
                    index = i;
                }
            }
            maxStep += index;
            counts++;
        }
        return counts;
    }
};
