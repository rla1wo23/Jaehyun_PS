#include <iostream>
using namespace std;
int N = 0;
pair<int, int> pos[81];
int board[9][9];
bool cross_check(int x, int y, int value) {
  for (int i = 0; i < 9; i++) {
    if (board[x][i] == value || board[i][y] == value) {
      return false;
    }
  }
  return true;
}
bool area_check(int x, int y, int value) {
  int x_d = x / 3;
  int y_d = y / 3;
  for (int i = x_d * 3; i < (3 + x_d * 3); i++) {
    for (int j = y_d * 3; j < (3 + y_d * 3); j++) {
      if (board[i][j] == value)
        return false;
    }
  }
  return true;
}
bool is_okay(int x, int y, int value) {
  return area_check(x, y, value) && cross_check(x, y, value);
}
bool kill_switch = false;
bool back_tracking(int k) {
  if (k == N) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j];
      }
      cout << "\n";
    }
    return true;
  } else {
    pair<int, int> cur = pos[k];
    for (int i = 0; i <= 9; i++) {
      if (is_okay(cur.first, cur.second, i)) {
        board[cur.first][cur.second] = i; // 넣어도 되면 넣고
        if (back_tracking(k + 1)) {       // 탐색 시작
          return true;
        }
        board[cur.first][cur.second] = 0;
      }
    }
    return false; // 이럼 그 위에서는 false라서 다시 시도해봐야함
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < 9; j++) {
      board[i][j] = str[j] - '0';
      if (board[i][j] == 0) {
        pos[N] = {i, j};
        N++;
      }
    }
  }
  back_tracking(0);
}