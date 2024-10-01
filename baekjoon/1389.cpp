#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  int board[105][105];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      board[i][j] = INF;
    }
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    board[u][v] = 1;
    board[v][u] = 1;
  }
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
      }
    }
  }
  int ans = INF;
  int ans_p = 1;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += board[i][j];
    }
    if (ans > sum) {
      ans = sum;
      ans_p = i;
    }
  }
  cout << ans_p;
}