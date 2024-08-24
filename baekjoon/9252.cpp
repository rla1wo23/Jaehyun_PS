#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int board[1001][1001];
int main() {
  string a, b;
  cin >> a >> b;
  for (int i = 0; i <= a.size(); i++) {
    board[i][0] = 0;
    board[0][i] = 0;
  }
  int max_length = 0;
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        board[i][j] = board[i - 1][j - 1] + 1;
        if (board[i][j] > max_length) {
          max_length = board[i][j];
        }
      } else {
        board[i][j] = max(board[i - 1][j], board[i][j - 1]);
      }
    }
  }
  if (max_length == 0) {
    cout << 0 << "\n";
  } else {
    int x = a.size();
    int y = b.size();
    stack<char> s;
    while (board[x][y] != 0) {
      if (board[x][y] == board[x - 1][y]) {
        x--;
      } else if (board[x][y] == board[x][y - 1]) {
        y--;
      } else {
        s.push(a[x - 1]);
        x--;
        y--;
      }
    }
    cout << max_length << "\n";
    while (!s.empty()) {
      cout << s.top();
      s.pop();
    }
  }
}