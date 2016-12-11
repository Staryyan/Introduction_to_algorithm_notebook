#include <iostream>
#include <vector>
#define MAX 1001
#define PARANT(i) i >> 1
#define LEFT(i) i << 1
#define RIGHT(i) (i << 1) + 1
using namespace std;
class Heap {
private:
    vector<int> data;
    int size{0};
    void heapify(int index) {
        int left = LEFT(index);
        int right = RIGHT(index);
        int largest = index;
        if (left <= size && data[left] > data[index]) {
            largest = left;
        } else {
            largest = index;
        }
        if (right <= size && data[right] > data[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(data[index], data[largest]);
            heapify(largest);
        }
    }
    void increaseKey(int index, int key) {
        if (key > data[index]) {
            data[index] = key;
            while (index > 1 && data[PARANT(index)] < data[index]) {
                swap(data[PARANT(index)], data[index]);
                index = PARANT(index);
            }
        }
    }
public:
    Heap() {
        data = vector<int>(MAX, 0);
    }
    Heap(vector<int> vec) {
        size = vec.size();
        data = vector<int>(size + 1, 0);
        for (int i = 0; i < vec.size(); ++i) {
            data[i + 1] = vec[i];
        }
        for (int j = size / 2; j >= 1; --j) {
            heapify(j);
        }
    }
    vector<int> heapSort() {
        int tSize = size;
        for (int j = size; j >= 1; --j) {
            swap(data[1], data[j]);
            size--;
            heapify(1);
        }
        size = tSize;
        vector<int> ans(data.begin() + 1, data.begin() + 1 + size);
        return ans;
    }
    int top() {
        return data[1];
    }
    int pop() {
        int max = data[1];
        swap(data[1], data[size]);
        size--;
        heapify(1);
        return max;
    }
};
int main() {
    Heap heap({2,3,1,4,10,2,3,1,4,10,2,3,1,4,10,2,3,1,4,10,2,3,1,4,10,2,3,1,4,10});
    vector<int> vec = heap.heapSort();
    for (auto each : vec) {
        cout << each << " ";
    }
}