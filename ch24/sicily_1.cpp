/**
 * 优先队列，拓扑排序
 */
#include <iostream>
#include <queue>
using namespace std;
int MAX = 100000;
int main() {
    int n; cin >> n;
    while (n--) {
        int vertex, edge;
        cin >> vertex >> edge;
        int inDegree[100001];
        vector<int> VertexVec[100001];
        for (int i = 1; i <= vertex; ++i) { inDegree[i] = 0; }
        int start, end;
        while (edge--) {
            cin >> start >> end;
            inDegree[end]++;
            VertexVec[start].push_back(end);
        }
        priority_queue<int, vector<int>, greater<int> > priorityQueue;
        for (int j = 1; j <= vertex; ++j) {
            if (inDegree[j] == 0) {
                priorityQueue.push(j);
            }
        }
        while (!priorityQueue.empty()) {
            int top = priorityQueue.top();
            priorityQueue.pop();
            cout << top << " ";
            for (int i = 0; i < VertexVec[top].size(); ++i) {
                inDegree[VertexVec[top][i]]--;
                if (inDegree[VertexVec[top][i]] == 0) {
                    priorityQueue.push(VertexVec[top][i]);
                }
            }
        }
        cout << endl;
    }
}