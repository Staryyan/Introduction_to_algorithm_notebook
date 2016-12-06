#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        if (row == 0) { return 0; }
        int col = heightMap[0].size();
        if (col == 0) { return 0; }
        /**
         * [height, <x, y>]
         */
        priority_queue<pair<int, pair<int, int>>> mapQueue;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < col; ++i) {
            visited[0][i] = true;
            visited[row - 1][i] = true;
            mapQueue.push(make_pair(-(int)heightMap[0][i], make_pair(0, i)));
            mapQueue.push(make_pair(-(int)heightMap[row - 1][i], make_pair(row - 1, i)));
        }
        for (int j = 1; j < row - 1; ++j) {
            visited[j][0] = true;
            visited[j][col- 1] = true;
            mapQueue.push(make_pair(-(int)heightMap[j][0], make_pair(j, 0)));
            mapQueue.push(make_pair(-(int)heightMap[j][col - 1], make_pair(j, col - 1)));
        }
        const int directionX[4] = {1, -1, 0, 0};
        const int directionY[4] = {0, 0, 1, -1};
        int result = 0;
        while (!mapQueue.empty()) {
            auto tmp = mapQueue.top();
            mapQueue.pop();
            int height = -tmp.first;
            int X = tmp.second.first;
            int Y = tmp.second.second;
            for (int i = 0; i < 4; ++i) {
                int tmpX = X + directionX[i];
                int tmpY = Y + directionY[i];
                if (tmpX < 0 || tmpY < 0 || tmpX >= row || tmpY >= col || visited[tmpX][tmpY]) { continue; }
                if (height > heightMap[tmpX][tmpY]) {
                    result += height - heightMap[tmpX][tmpY];
                    heightMap[tmpX][tmpY] = height;
                }
                visited[tmpX][tmpY] = true;
                mapQueue.push(make_pair(-((int)heightMap[tmpX][tmpY]), make_pair(tmpX, tmpY)));
            }
        }
        return result;
    }
};