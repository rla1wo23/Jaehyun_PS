#include <iostream>
const int INF = 0x3f3f3f3f;
using namespace std;
int n, m, r;
int board[105][105];
int value[105];
int main() {
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> value[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      board[i][j] = INF;
      if (i == j) {
        board[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    board[a][b] = min(board[a][b], c);
    board[b][a] = min(board[b][a], c);
  }
  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      for (int e = 1; e <= n; e++) {
        board[s][e] = min(board[s][e], board[s][k] + board[k][e]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cand = 0;
    for (int j = 1; j <= n; j++) {
      if (board[i][j] <= m)
        cand += value[j];
    }
    ans = max(cand, ans);
  }
  cout << ans;
}