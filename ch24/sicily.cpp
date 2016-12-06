#include <vector>
#include <map>
#include <iostream>
#include <memory.h>
using namespace std;
int MAX = 1000;
int main() {
    int n; cin >> n;
    while (n--) {
        int graph[1000][1000];
        memset(graph, 0, sizeof(graph));
        map<string, int> idMap;
        int edge; cin >> edge;
        string start, des; int distance, id = 0;
        while (edge--) {
            cin >> start >> des >> distance;
            if (idMap.find(start) == idMap.end()) {
                idMap.insert(pair<string, int>(start, id++));
            }
            if (idMap.find(des) == idMap.end()) {
                idMap.insert(pair<string, int>(des, id++));
            }
            graph[idMap[start]][idMap[des]] = distance;
            graph[idMap[des]][idMap[start]] = distance;
        }
        cin >> start >> des;
        if (start == des) { cout << 0 << endl; continue; }
        if (idMap.find(start) == idMap.end() || idMap.find(des) == idMap.end()) { cout << -1 << endl; continue; }

        vector<int> resGraph(id, MAX); // 存储最终图，表示距离。
        int next = idMap[start];
        resGraph[next] = 0;
        vector<bool> used(id, false); used[next] = true;
        int count = 1;
        for (int j = 0; j < id; ++j) {
            if (graph[next][j] != 0) { resGraph[j] = graph[next][j]; }
        }
        while (count < id) {
            int localMin = MAX;
            for (int i = 0; i < id; ++i) {
                if (localMin > resGraph[i] && !used[i]) {
                    localMin = resGraph[i];
                    next = i;
                }
            }
            used[next] = true;
            count++;
            for (int j = 0; j < id; ++j) {
                if (graph[next][j] != 0 && !used[j] && resGraph[j] > localMin + graph[next][j]) {
                    resGraph[j] = localMin + graph[next][j];
                }
            }
        }
        if (resGraph[idMap[des]] == MAX) {
            cout << -1 << endl;
        } else {
            cout << resGraph[idMap[des]] << endl;
        }
    }
    return 0;
}
