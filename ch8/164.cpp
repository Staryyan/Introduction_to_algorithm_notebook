/**
 * bucket sort.
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) { return 0; }
        int n = (int)nums.size();
        int minV = INT_MAX, maxV = INT_MIN;
        for (auto each : nums) {
            if (each < minV) { minV = each; }
            if (each > maxV) { maxV = each; }
        }
        if (maxV == minV) { return 0; }
        int bucketSize = max(1, (maxV - minV) / (n - 1));
        int bucketNum = (maxV - minV) / bucketSize + 1;
        if (bucketNum == 1) { return maxV - minV; }
        vector<int> counter(bucketNum, 0);
        vector<int> bucketMin(bucketNum, INT_MAX);
        vector<int> bucketMax(bucketNum, INT_MIN);
        int id = 0;
        for (auto each : nums) {
            id = (each - minV) / bucketSize;
            counter[id]++;
            bucketMin[id] = min(bucketMin[id], each);
            bucketMax[id] = max(bucketMax[id], each);
        }
        int lastMax = minV, maxGap = 0;
        for (int i = 0; i < bucketNum; ++i) {
            if (counter[i]) {
                maxGap = max(maxGap, bucketMin[i] - lastMax);
                lastMax = bucketMax[i];
            }
        }
        return maxGap;
    }
};