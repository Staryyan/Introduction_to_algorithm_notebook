#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int directionRow[4] = {1, -1, 0, 0};
    int directionCol[4] = {0, 0, 1, -1};
    void visit(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (visited[i][j]) { return; }
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> visitedQueue;
        visitedQueue.push({i, j});
        while (!visitedQueue.empty()) {
            auto tmp = visitedQueue.front();
            visitedQueue.pop();
            int _row = tmp.first;
            int _col = tmp.second;
            if (visited[_row][_col]) { continue; }
            visited[_row][_col] = true;
            for (int k = 0; k < 4; ++k) {
                int tmpRow = _row + directionRow[k];
                int tmpCol = _col + directionCol[k];
                if (tmpRow >= 0 && tmpRow <= row - 1 && tmpCol >= 0 && tmpCol <= col - 1 && grid[tmpRow][tmpCol] == '1') {
                    visitedQueue.push({tmpRow, tmpCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) { return 0; }
        int col = grid[0].size();
        if (col == 0) { return 0; }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    visit(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};