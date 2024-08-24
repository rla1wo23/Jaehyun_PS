#include <algorithm>
#include <iostream>
using namespace std;
int board[2005][2005] = {0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i <= N; i++) {
    board[i][0] = 0;
    board[0][i] = 0;
    board[i][N + 1] = 0;
  }
  int date[2005];
  date[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> date[i];
  }
  date[N + 1] = 0;
  int ans = 0;
  board[1][N] = 0;
  for (int d = 1; d <= N - 1; d++) { // 1에서 4일까지
    for (int i = 0; i < d + 1; i++) {
      int x = 1 + i;
      int y = N - d + i;
      board[x][y] = max(board[x - 1][y] + date[x - 1] * d,
                        board[x][y + 1] + date[y + 1] * d);
    }
  }
  for (int i = 1; i <= N; i++) {
    ans = max(board[i][i] + date[i] * N, ans);
  }
  cout << ans;
}
