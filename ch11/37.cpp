class Solution {
public:
    bool col[10][10];
    bool row[10][10];
    bool block[10][10];
    bool finished = false;
    void solveSudoku(vector<vector<char>>& board) {
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(block, false, sizeof(block));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    int blockId = i / 3 + 3 * (j / 3);
                    block[blockId][board[i][j] - '0'] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (finished) { return ; }
        if (i == 9) {
            finished = true;
            return;
        }
        if (board[i][j] != '.') {
            if (j == 8) { dfs(board, i + 1, 0); }
            else { dfs(board, i, j + 1); }
            if (finished) { return; }
        } else {
            for (int k = 1; k < 10; ++k) {
                int blockId = i / 3 + 3 * (j / 3);
                if (!row[i][k] && !col[j][k] && !block[blockId][k]) {
                    board[i][j] = k + '0';
                    row[i][board[i][j] - '0'] = col[j][board[i][j] - '0'] = block[blockId][board[i][j] - '0'] = true;
                    if (j == 8) { dfs(board, i + 1, 0); }
                    else { dfs(board, i, j + 1); }
                    row[i][board[i][j] - '0'] = col[j][board[i][j] - '0'] = block[blockId][board[i][j] - '0'] = false;
                    if (finished) { return; }
                }
            }
            board[i][j] = '.';
        }
    }
};