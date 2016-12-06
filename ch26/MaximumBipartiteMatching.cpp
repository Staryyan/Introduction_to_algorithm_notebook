/**
 * 最大二分图算法。
 * 转换为一个多源多节点最大流问题。
 * 每条边的最大流量为1。
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MATRIX vector<vector<int>>
#define MAXSIZE 200
#define MaxData 1
int vertexes, edges;
MATRIX capacity(MAXSIZE, vector<int>(MAXSIZE, 0));
vector<int> pre(MAXSIZE, -1);
vector<int> flow(MAXSIZE, 0);
int BFS(int src, int des) {
    queue<int> _queue;
    while (!_queue.empty()) { _queue.pop(); }
    for (int i = 1; i <= vertexes; ++i) { pre[i] = -1; }
    pre[src] = 0;
    flow[src] = MaxData;
    _queue.push(src);
    while (!_queue.empty()) {
        int index = _queue.front();
        _queue.pop();
        if (index == des) { break; }
        for (int i = 1; i <= vertexes; ++i) {
            if (src != i && capacity[index][i] > 0 && pre[i] == -1) {
                pre[i] = index;
                flow[i] = min(capacity[index][i], flow[index]);
                _queue.push(i);
            }
        }
    }
    if (pre[des] == -1) { return -1; }
    return flow[des];
}
int multi_maxFlow(vector<int> src, vector<int> des) {
    int start = 0, end = vertexes + 1;
    for (auto each : src) { capacity[start][each] = MaxData; }
    for (auto each : des) { capacity[each][end] = MaxData; }
    int increasement = 0;
    int sumFlow = 0;
    vertexes++;
    while ((increasement = BFS(start, end)) != -1) {
        int index = end;
        while (index != start) {
            int last = pre[index];
            capacity[last][index] -= increasement;
            capacity[index][last] += increasement;
            index = last;
        }
        sumFlow += increasement;
    }
    return sumFlow;
}
int main() {
    while (cin >> vertexes >> edges) {
        for (int j = 1; j <= vertexes; ++j) {
            for (int i = 1; i <= vertexes; ++i) {
                capacity[j][i] = 0;
            }
        }
        int start, end, ci;
        for (int i = 0; i < edges; ++i) {
            cin >> start >> end;
            if (start == end) { continue; }
            capacity[start][end] += 1;
        }
        vector<int> src, des;
        int srcSize, desSize;
        cin >> srcSize >> desSize;
        int tmp = 0;
        while (srcSize--) { cin >> tmp; src.push_back(tmp); }
        while (desSize--) { cin >> tmp; des.push_back(tmp); }
        cout << multi_maxFlow(src, des) << endl;
    }
}
