#include <vector>
#include <iostream>
using namespace std;
void merge(vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftVec(n1 + 1, 0);
    vector<int> rightVec(n2 + 1, 0);
    for (int i = 0; i < n1; ++i) {
        leftVec[i] = vec[left + i];
    }
    leftVec[n1] = INT_MAX;
    for (int j = 0; j < n2; ++j) {
        rightVec[j] = vec[mid + j + 1];
    }
    rightVec[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = left; k <= right; ++k) {
        if (leftVec[i] < rightVec[j]) {
            vec[k] = leftVec[i++];
        } else {
            vec[k] = rightVec[j++];
        }
    }
}
void mergeSortImpl(vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSortImpl(vec, left, mid);
        mergeSortImpl(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}
void mergeSort(vector<int>& vec) {
    mergeSortImpl(vec, 0, vec.size() - 1);
}
int main() {
    vector<int> vec{2,3,1,2,4,3,2,1,5,6,4,2,1,2,3,1,2,4,3,2,1,5,6,4,2,1,2,3,1,2,4,3,2,1,5,6,4,2,1,2,3,1,2,4,3,2,1,5,6,4,2,1,2};
    mergeSort(vec);
    for (auto each : vec) {
        cout << each << " ";
    }
    cout << endl;
}
