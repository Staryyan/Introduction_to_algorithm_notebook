#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > nodeQueue;
/**
 * 堆排序适合于数据量非常大的场合（百万数据）。
 * 堆排序不需要大量的递归或者多维的暂存数组。
 * 这对于数据量非常巨大的序列是合适的。
 * 比如超过数百万条记录，因为快速排序，
 * 归并排序都使用递归来设计算法，在数据量非常大的时候，可能会发生堆栈溢出错误
 * @return
 */
int main() {
    int n, m, tmp;
    while (cin >> n >> m && (n != 0 && m != 0)) {
        for (int i = 0; i < n; ++i) {
            cin  >> tmp; nodeQueue.push(tmp);
        }
        cout << nodeQueue.top();
        nodeQueue.pop();
        int cnt = 1;
        while (!nodeQueue.empty()) {
            int top = nodeQueue.top();
            nodeQueue.pop();
            if (cnt % m == 0) { cout << " " << top;}
            cnt = (cnt + 1) % n;
        }
        cout << endl;
    }
    return 0;
}
