#include <iostream>
using namespace std;
int N, L;
int board[105][105] = {0};
bool can_construct(int x, int y, int dir) {
  // x,y에서, dir방향으로 build할 수 있는지 체크
  if (x < 0 || y < 0)
    return false;
  int dx = 1;
  int dy = 0;
  if (dir == 1) {
    dx = 0;
    dy = 1;
  }
  if (x + dx * L > N || y + dy * L > N)
    return false;
  int cur = board[x][y];
  for (int i = 0; i < L; i++) {
    if (cur != board[x + dx * i][y + dy * i])
      return false;
  }
  return true;
}
bool check_x(int y) { // 0,y에서 아래 일렬로 다리를 놓을 수 있는지
  int x = 0;
  bool constructed[105];
  for (int i = 0; i < N; i++) {
    constructed[i] = false;
  }
  int cur = board[x][y];
  while (x < N) {
    if (x == N - 1) {
      return true;
    }
    if (cur == board[x + 1][y]) {
      x++;
    } else {
      if (board[x + 1][y] == cur + 1) { // 더 높은거 만남
        if (can_construct(x - L + 1, y, 0)) {
          for (int i = x - L + 1; i <= x; i++) {
            if (constructed[i]) {
              return false;
            }
            constructed[i] = true;
          }
          cur++;
          x++;
        } else {
          return false;
        }
      } else if (board[x + 1][y] == cur - 1) { // 더 낮은거
        if (can_construct(x + 1, y, 0)) {
          for (int i = 1; i <= L; i++) {
            if (constructed[x + i]) {
              return false;
            }
            constructed[x + i] = true;
          }
          cur--;
          x += L; // x
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}
bool check_y(int x) {
  // x,0에서 y축 일렬로 다리를 놓을 수 있는지
  int y = 0;
  bool constructed[105] = {false};
  while (y < N) {
    if (y == N - 1) {
      return true;
    }
    if (board[x][y] == board[x][y + 1]) {
      y++;
    } else {
      if (board[x][y + 1] == board[x][y] + 1) {
        if (can_construct(x, y - L + 1, 1)) {
          for (int i = y - L + 1; i <= y; i++) {
            if (constructed[i])
              return false;
            constructed[i] = true;
          }
          y++;
        } else {
          return false;
        }
      } else if (board[x][y + 1] == board[x][y] - 1) {
        if (can_construct(x, y + 1, 1)) {
          for (int i = 1; i <= L; i++) {
            if (constructed[y + i])
              return false;
            constructed[y + i] = true;
          }
          y++;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}
int main() {
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (check_x(i))
      ans++;
    if (check_y(i))
      ans++;
  }
  cout << ans;
}