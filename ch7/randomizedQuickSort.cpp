#include<iostream>
#include <vector>
#include <random>
using namespace std;
class QuickSort{
public:
    int partition(vector<int>& vec, int left, int right) {
        int x = vec[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (vec[j] < x) {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[right]);
        return i + 1;
    }
    int randomizedPartition(vector<int>& vec, int left, int right) {
        int randomPivot = random() % (right - left) + left;
        swap(vec[randomPivot], vec[right]);
        return partition(vec, left, right);
    }
    void quickSortImpl(vector<int>& vec, int start, int end) {
        if (start < end) {
            int mid = randomizedPartition(vec, start, end);
            quickSortImpl(vec, start, mid - 1);
            quickSortImpl(vec, mid + 1, end);
        }
    }
    void quickSort(vector<int>& vec) {
        quickSortImpl(vec, 0, (int)vec.size() - 1);
    }
};
int main() {
    vector<int> vec{1,2,3,4,5,6,2,1,2,3,4,5,6,7,2,3,4,5,6};
    QuickSort qs;
    qs.quickSort(vec);
    for (auto each : vec) {
        cout << each << " ";
    }
    cout << endl;
}