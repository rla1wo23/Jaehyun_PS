#include <algorithm>
#include <iostream>
using namespace std;
char board[55][55];
int N, M;
bool rcheck(int r) { // 이 행을 체워야하는지
  for (int c = 0; c < N; c++) {
    if (board[r][c] == 'X')
      return false;
  }
  return true;
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (rcheck(i)) {
      bool fd = false;
      for (int j = c; j < M; j++) {
        for (int k = i; k < N; k++) {
          if (board[k][c] == '.') {
            ans++;
            fd = true;
            break;
          }
        }
        if (fd)
          break;
      }
    }
  }
}