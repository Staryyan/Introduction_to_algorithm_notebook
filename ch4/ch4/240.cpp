/**
 * Divide and conquer.
 */
class Solution {
private:
    bool searchMatixImpl(vector<vector<int>>& matrix, int target, int rowUp, int rowDown, int colLeft, int colRight) {
        if (colLeft > colRight || rowUp > rowDown) { return false; }
        if (colLeft == colRight && rowUp == rowDown) { return matrix[rowDown][colLeft] == target; }
        if (target < matrix[rowUp][colLeft] || target > matrix[rowDown][colRight]) { return false; }
        int rowMid = (rowUp + rowDown) / 2;
        int colMid = (colLeft + colRight) / 2;
        return searchMatixImpl(matrix, target, rowUp, rowMid, colLeft, colMid) ||
               searchMatixImpl(matrix, target, rowMid + 1, rowDown, colLeft, colMid) ||
               searchMatixImpl(matrix, target, rowUp, rowMid, colMid + 1,  colRight) ||
               searchMatixImpl(matrix, target, rowMid + 1, rowDown, colMid + 1, colRight);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatixImpl(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};