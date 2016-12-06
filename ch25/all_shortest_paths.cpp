#include <iostream>
#include <vector>
using namespace std;
#define Matrix vector<vector<int>>
#define MAX 1000
Matrix EXTEND_SHORTEST_PATHS(Matrix L, Matrix W) {
    int row = (int)L.size();
    Matrix newL = L;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            newL[i][j] = MAX;
            for (int k = 0; k < row; ++k) {
                newL[i][j] = min(newL[i][j], L[i][k] + W[k][j]);
            }
        }
    }
    return newL;
}

Matrix Slower_ALL_PATHS_SHORTEST_PATHS(Matrix W) {
    int row = (int)W.size();
    Matrix L = W;
    for (int i = 2; i < row; ++i) {
        L = EXTEND_SHORTEST_PATHS(L, W);
    }
    return L;
}

Matrix FASTER_ALL_PATHS_SHORTEST_PATHS(Matrix W) {
    int row = (int)W.size();
    Matrix L = W;
    int m = 1;
    while (m < row - 1) {
        L = EXTEND_SHORTEST_PATHS(L, L);
        m = 2 * m;
    }
    return L;
}

Matrix FLOYD_WARSHALL(Matrix W) {
    int row = W.size();
    Matrix D = W;
    for (int k = 0; k < row; ++k) {
        Matrix tmp = D;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < row; ++j) {
                tmp[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
        D = tmp;
    }
    return D;
}

void showMatrix(Matrix m) {
    int row = m.size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix graph{{0,3,8,MAX,-4}, {MAX, 0, MAX, 1, 7}, {MAX, 4, 0, MAX, MAX}, {2, MAX, -5, 0, MAX}, {MAX, MAX, MAX, 6, 0}};
    showMatrix(graph);
    cout << endl;
    showMatrix(FASTER_ALL_PATHS_SHORTEST_PATHS(graph));
    cout << endl;
    showMatrix(Slower_ALL_PATHS_SHORTEST_PATHS(graph));
    cout << endl;
    showMatrix(FLOYD_WARSHALL(graph));
    cout << endl;
}
