#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int board[105][105];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][k] == 1 && board[k][j] == 1) {
          board[i][j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}