#include <iostream>
using namespace std;

int board[5][5];

int bingo_cnt() {
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    int turn1 = 0;
    int turn2 = 0;
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == -1)
        turn1++;
      if (board[j][i] == -1)
        turn2++;
    }
    if (turn1 == 5)
      cnt++;
    if (turn2 == 5)
      cnt++;
  }
  int lc = 0;
  int rc = 0;
  for (int i = 0; i < 5; i++) {
    if (board[i][i] == -1)
      lc++;
    if (board[4 - i][i] == -1)
      rc++;
  }
  if (lc == 5)
    cnt++;
  if (rc == 5)
    cnt++;
  return cnt;
}

void find_and_check(int k) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == k) {
        board[i][j] = -1;
        return;
      }
    }
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> board[i][j];
    }
  }

  int turn = 0;
  bool checked = false;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      turn++;
      int x;
      cin >> x;
      if (checked)
        continue;
      find_and_check(x);
      if (bingo_cnt() >= 3) {
        cout << turn;
        checked = true;
        break;
      }
    }
    if (checked)
      break;
  }
}
