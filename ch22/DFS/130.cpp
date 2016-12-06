class Solution {
private:
    int directionX[4] = {1, -1, 0, 0};
    int directionY[4] = {0, 0, 1, -1};
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) { return; }
        int col = board[0].size();
        if (col == 0) { return; }
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> boardQueue;
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') { boardQueue.push({0, i}); }
            if (board[row - 1][i] == 'O') { boardQueue.push({row - 1, i}); }
        }
        for (int j = 1; j < row - 1; ++j) {
            if (board[j][0] == 'O') { boardQueue.push({j, 0}); }
            if (board[j][col - 1] == 'O') { boardQueue.push({j, col - 1}); }
        }
        while (!boardQueue.empty()) {
            auto tmp = boardQueue.front();
            boardQueue.pop();
            if (visited[tmp.first][tmp.second]) { continue; }
            visited[tmp.first][tmp.second] = true;
            for (int i = 0; i < 4; ++i) {
                int _row = tmp.first + directionX[i];
                int _col = tmp.second + directionY[i];
                if (_row >= 0 && _row <= row - 1 && _col >= 0 && _col <= col - 1 && board[_row][_col] == 'O') {
                    boardQueue.push({_row, _col});
                }
            }
        }
        for (int k = 0; k < row; ++k) {
            for (int i = 0; i < col; ++i) {
                if (board[k][i] == 'O' && !visited[k][i]) {
                    board[k][i] = 'X';
                }
            }
        }
    }
};