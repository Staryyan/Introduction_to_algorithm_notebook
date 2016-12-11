/**
 * 最大子串，分治算法。  
 */
#include <vector>
#include <iostream>
using namespace std;
int findMaxCrossingSubarray(vector<int>& vec, int lower, int upper) {
    int mid = (lower + upper) / 2;
    int leftSUm = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= lower; --i) {
        sum += vec[i];
        leftSUm = max(leftSUm, sum);
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= upper; ++j) {
        sum += vec[j];
        rightSum = max(rightSum, sum);
    }
    return leftSUm + rightSum;
}
int findMaxSubarrayImpl(vector<int>& vec, int lower, int upper) {
    if (lower == upper) { return vec[lower]; }
    int mid = (lower + upper) / 2;
    int leftSum = findMaxSubarrayImpl(vec, lower, mid);
    int rightSum = findMaxSubarrayImpl(vec, mid + 1, upper);
    int crossingSUm = findMaxCrossingSubarray(vec, lower, upper);
    return max(leftSum, max(rightSum, crossingSUm));
}
int findMaxSubarray(vector<int>& vec) {
    vector<int> dis(vec.size() - 1, 0);
    for (int i = 1; i < vec.size(); ++i) {
        dis[i - 1] = vec[i] - vec[i - 1];
    }
    return findMaxSubarrayImpl(dis, 0, dis.size() - 1);
}
int main() {
    vector<int> stock{100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    cout << findMaxSubarray(stock) << endl;
    return 0;
}
