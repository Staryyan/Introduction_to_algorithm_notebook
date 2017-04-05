#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& src, vector<int>& des, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i != mid + 1 && j != right + 1) {
        if (src[i] < src[j]) {
            des[k++] = src[i++];
        } else {
            des[k++] = src[j++];
        }
    }
    while (i != mid + 1) { des[k++] = src[i++]; }
    while (j != right + 1) { des[k++] = src[j++]; }
    for (int l = left; l <= right; ++l) {
        src[l] = des[l];
    }
}

void mergeSortImpl(vector<int>& src, vector<int>& des, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortImpl(src, des, left, mid);
        mergeSortImpl(src, des, mid + 1, right);
        merge(src, des, left, mid, right);
    }
}

void mergeSort(vector<int>& vec) {
    vector<int> ans = vec;
    mergeSortImpl(vec, ans, 0, (int)ans.size() - 1);
}

int main() {
    vector<int> src{1,2,1,2,3,1,10,20,340,20,2,1,2,3,1,10,20,340,20,2,1,2,3,1,10,20,340,20,2,1,2,3,1,10,20,340,20,2,1,2,3,1,10,20,340,20};
    mergeSort(src);
    for (int i = 0; i < src.size(); ++i) {
        cout << src[i] << " ";
    }
    cout << endl;
}
