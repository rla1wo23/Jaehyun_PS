#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int board[105][105];
int nxt[105][105];
const int INF = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      board[i][j] = INF;
      if (i == j) {
        board[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (board[a][b] > c) {
      board[a][b] = c;
      nxt[a][b] = b;
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      for (int e = 1; e <= n; e++) {
        if (board[s][e] > board[s][k] + board[k][e]) {
          board[s][e] = board[s][k] + board[k][e];
          nxt[s][e] = nxt[s][k];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (board[i][j] == INF) {
        cout << 0 << " ";
      } else {
        cout << board[i][j] << " ";
      }
    }
    cout << "\n";
  }
  for (int i = 1; i <= n; i++) { // i에서, j로 가는 경로 출력해야 함
    for (int j = 1; j <= n; j++) {
      if (board[i][j] == 0 || board[i][j] == INF) {
        cout << 0 << "\n";
        continue;
      }
      vector<int> v;
      int st = i;
      int en = j;
      v.push_back(st);
      while (st != en) {
        v.push_back(nxt[st][en]);
        st = nxt[st][en];
      }
      cout << v.size() << " ";
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
      cout << "\n";
    }
  }
}