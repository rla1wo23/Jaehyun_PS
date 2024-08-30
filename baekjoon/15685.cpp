#include <iostream>
#include <vector>
using namespace std;
int board[105][105][2] = {0}; // 0:우향, //1:상향(-)
pair<int, int> color_and_move(int dir, int x, int y) {
  if (dir == 0) { // 우로 놓고 이동
    board[x][y][0] = 1;
    return {x + 1, y};
  } else if (dir == 1) { // 위로 이동
    board[x][y][1] = 1;
    return {x, y - 1};
  } else if (dir == 2) {    // 좌로 이동
    board[x - 1][y][0] = 1; // 좌측의 우향을 체크
    return {x - 1, y};
  } else {
    board[x][y + 1][1] = 1; // 아래로 이동
    return {x, y + 1};
  }
}
int main() {
  int N;
  cin >> N;
  vector<int> log;
  log.push_back(0);
  for (int i = 1; i <= 10; i++) {
    int lim = log.size();
    for (int j = 1; j <= lim; j++) {
      int nxt = (log[lim - j] + 5) % 4;
      log.push_back(nxt);
    }
  }

  while (N--) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    int search = pow(2, g);
    for (int i = 0; i < search; i++) {
      int nd = (log[i] + d) % 4;
      pair<int, int> nxt = color_and_move(nd, x, y);
      x = nxt.first;
      y = nxt.second;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (board[i][j][0] == 1 && board[i][j][1] == 1 &&
          board[i - 1][j][0] == 1 && board[i][j + 1][1] == 1) {
        ans++;
      }
    }
  }
  cout << ans;
}
