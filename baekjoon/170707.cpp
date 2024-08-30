#include <algorithm>
#include <iostream>
using namespace std;
int N;
int ans = 0;
int board[20][20] = {0};
bool corss_check(int x, int y) { // x,y에서 대각선으로 전진 가능한지 여부
  return board[x + 1][y] == 0 && board[x + 1][y + 1] == 0 &&
         board[x][y + 1] == 0 && x + 1 < N && y + 1 < N;
}
void back_track(pair<int, int> head, int dir) {
  int x = head.first;
  int y = head.second;
  if (x == N - 1 && y == N - 1) {
    ans++;
    return;
  }
  if (corss_check(x, y)) {
    back_track({x + 1, y + 1}, 2);
  }
  if (dir != 1) {
    if (board[x][y + 1] == 0 && y + 1 < N) { // 오른쪽에 머 없음 댐
      back_track({x, y + 1}, 0);
    }
  }
  if (dir != 0) { // 세로방향 전진 가능한지
    if (board[x + 1][y] == 0 && x + 1 < N) {
      back_track({x + 1, y}, 1);
    }
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  back_track({0, 1}, 0);
  cout << ans;
}