/**
 * 桶排序，确定bucketSize和bucketNum，可以确定排序的效率。
 */
vector<int> bucketSort(vector<int> in) {
    int bucketMin = INT_MAX, bucketMax = INT_MIN;
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] < bucketMin) { bucketMin = in[i]; }
        else if (in[i] > bucketMax) { bucketMax = in[i]; }
    }
    int bucketNum = 4;
    int bucketSize = (bucketMax - bucketMin) / bucketNum;
    vector<vector<int>> buckets(bucketNum + 1, vector<int>{});
    for (int j = 0; j < in.size(); ++j) {
        buckets[(in[j] - bucketMin) / bucketSize].push_back(in[j]);
    }
    for (int k = 0; k <= bucketNum; ++k) {
        sort(buckets[k].begin(), buckets[k].end());
    }
    vector<int> out;
    for (int l = 0; l <= bucketNum; ++l) {
        for (auto each : buckets[l]) {
            out.push_back(each);
        }
    }
    return out;
}
