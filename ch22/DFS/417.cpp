#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    void flow(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
        if (visited[i][j]) { return; }
        int row = matrix.size();
        int col = matrix[0].size();
        queue<pair<int, int>> visitedQueue;
        visitedQueue.push({i, j});
        while (!visitedQueue.empty()) {
            auto tmp = visitedQueue.front();
            visitedQueue.pop();
            int _row = tmp.first;
            int _col = tmp.second;
            if (visited[_row][_col]) { continue; }
            visited[_row][_col] = true;
            if (_row > 0 && matrix[_row - 1][_col] >= matrix[_row][_col]) { visitedQueue.push({_row - 1, _col}); }
            if (_row < row - 1 && matrix[_row + 1][_col] >= matrix[_row][_col]) { visitedQueue.push({_row + 1, _col}); }
            if (_col > 0 && matrix[_row][_col - 1] >= matrix[_row][_col]) { visitedQueue.push({_row, _col - 1}); }
            if (_col < col - 1 && matrix[_row][_col + 1] >= matrix[_row][_col]) { visitedQueue.push({_row, _col + 1}); }
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) { return {}; }
        int col = matrix[0].size();
        if (col == 0) { return {}; }

        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> alt(row, vector<bool>(col, false));

        for (int i = 0; i < col; ++i) {
            flow(0, i, matrix, pac);
            flow(row - 1, i, matrix, alt);
        }

        for (int j = 0; j < row; ++j) {
            flow(j, 0, matrix, pac);
            flow(j, col - 1, matrix, alt);
        }

        vector<pair<int, int>> ans;
        for (int k = 0; k < row; ++k) {
            for (int i = 0; i < col; ++i) {
                if (pac[k][i] && alt[k][i]) {
                    ans.push_back(make_pair(k, i));
                }
            }
        }
        return ans;
    }
};