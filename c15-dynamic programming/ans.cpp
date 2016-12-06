#include <iostream>
#include <map>
#include <cstring>

using namespace std;

#define MAX 210
#define MAX_NUM 200000
int Map[MAX][MAX];
bool visited[MAX];
int dis[MAX];

int main() {
    int test, n, d;
    string si, di;
    cin >> test;
    while (test--) {
        map<string, int> m;
        int index = 0, start, end;
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < 2 * n; j++) {
              if (i == j)
                  Map[i][j] = 0;
              else
                  Map[i][j] = MAX_NUM;
            }
        for (int i = 0;  i < n; i++) {
            cin >> si >> di >> d;
            if (m.find(si) == m.end()) {
                m.insert(pair<string, int>(si, index));
                start = index;
                index++;
            } else
                start = m[si];
            if (m.find(di) == m.end()) {
                m.insert(pair<string, int>(di, index));
                end = index;
                index++;
            } else
                end = m[di];
            Map[start][end] = d;
            Map[end][start] = d;
        }
        cin >> si >> di;
                //坑爹的样例，还老子WA了一晚上，当输入的地点不在所输入的路径里时，若两个地点相同，也输出０
        if (si == di) {
            cout << 0 << endl;
            continue;
        }
        if (m.find(si) == m.end() || m.find(di) == m.end()) {
          cout  << -1 << endl;
          continue;
        }
        start = m[si];
        end = m[di];

        memset(visited, false, sizeof(visited));
        for (int i = 0; i < index; i++) {
            dis[i] = Map[i][start];
        }
        visited[start] = true;
        dis[start] = 0;
        while (1) {
            int min = MAX_NUM, v;
            for (int i = 0 ; i < index; i++) {
                if (!visited[i] && min > dis[i]) {
                    min = dis[i];
                    v = i;
                }
            }
            if (min == MAX_NUM) break;
            visited[v] = true;
            for (int i = 0; i < index; i++) {
                if (!visited[i] && Map[v][i] + min < dis[i])
                  dis[i] = Map[v][i] + min;
            }
        }

        if (dis[end] == MAX_NUM)
          cout << -1 << endl;
        else
          cout << dis[end] << endl;
    }
}