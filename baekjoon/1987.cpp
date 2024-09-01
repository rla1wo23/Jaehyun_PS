#include <algorithm>
#include <iostream>
using namespace std;
int R, C;
bool is_used[26] = {false};
int board[25][25];
int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x, int y, int k) {
  ans = max(ans, k);
  if (x == R && y == C) {
    return;
  } else {
    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if (nx < 0 || ny < 0 || nx >= R || ny >= C)
        continue;
      if (is_used[board[nx][ny]])
        continue;
      is_used[board[nx][ny]] = true;
      bfs(nx, ny, k + 1);
      is_used[board[nx][ny]] = false;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char c;
      cin >> c;
      board[i][j] = c - 'A';
    }
  }
  is_used[board[0][0]] = true;
  bfs(0, 0, 1);
  cout << ans;
}