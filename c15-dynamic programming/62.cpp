/**
 * 62
 * https://leetcode.com/problems/unique-paths/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int graph[101][101];
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    graph[1][1] = 1;
                } else {
                    graph[i][j] = graph[i - 1][j] + graph[i][j - 1];
                }
            }
        }
        return graph[m][n];
    }
};