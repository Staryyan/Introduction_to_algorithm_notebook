#include <limits.h>
#include <iostream>
#define MaxInt numeric_limits<int>::max()
#define MaxEle 1000
using namespace std;
int map[MaxEle][MaxEle];
int visited[MaxEle];
int distance_low[MaxEle];
/**
 *  compute the minimal spanning tree
 *
 *  @param n the size of matrix
 *
 *  @return the minimal value of MST
 */
int prim(int n) {
	int path = 0;
  int pos, min, MST = 0;
  //  The array 'visited' represent which
  //  vertix has been visited already to avoid forming circle.
  visited[1] = 1;
  pos = 1;
  //  The array 'distance_distance_low' represent that
  //  arriving vertix i will cost distance_distance_low[i] steps now.
  for (int i = 2; i <= n; i++) {
    if (map[pos][i] == 0) {
      distance_low[i] = MaxInt;
    } else {
      distance_low[i] = map[pos][i];
    }
  }
  // manipulate n-1 times at all.
  for (int i = 1; i <= n - 1; i++) {
    min = MaxInt;
    // Find the minimal value of distance
    // and corresponding position.
    for (int j = 1; j <= n; j++) {
      if (visited[j] == 0 && min > distance_low[j]) {
        min = distance_low[j];
        pos = j;
      }
    }
    visited[pos] = 1;
    MST += min;
    path = min;
    //  Because of add a new vertix, it is neccessary to
    //  reload the information of 'distance_low'.
    for (int j = 1; j <= n; j++) {
      if (visited[j] == 0 && distance_low[j] > map[pos][j]) {
        if (map[pos][j] != 0) {
          distance_low[j] = map[pos][j];
        }
      }
    }
  }
  return path;
}
int main() {
  int size;
  /**
   *  input the size of matrix
   */
  cin >> size;
  while (size--) {
    // Initialise the map;
    memset(map, MaxInt, sizeof(map));
    /**
     *  input matrix information in ordered.
     */
    int n; cin >> n;
    for (int i = 1; i != n + 1; i++) {
      for (int j = 1; j != n + 1; j++) {
        cin >> map[i][j];
      }
    }
    int ans = prim(n);
    cout << ans << endl;
  }
  return 0;
}