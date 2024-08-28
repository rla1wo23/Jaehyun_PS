#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N, M, H;
vector<pair<int, int>> v;
int board[35][15] = {0};
int ans = 99;
bool can_construct(int x, int y) {
  if (abs(board[x][y]) == 1 || abs(board[x][y + 1]) == 1) {
    return false;
  }
  return true;
}

bool simul() {
  for (int i = 1; i <= N; i++) {
    int col = i;
    for (int row = 1; row <= H; row++) {
      col += board[row][col];
    }
    if (col != i) {
      return false;
    }
  }
  return true;
}

void back_tracking(int k, int idx) {
  if (k == 4)
    return;
  if (simul()) {
    ans = min(ans, k);
    return;
  }
  for (int i = idx; i < v.size(); i++) {
    if (!can_construct(v[i].first, v[i].second))
      continue;
    board[v[i].first][v[i].second] = 1;
    board[v[i].first][v[i].second + 1] = -1;
    back_tracking(k + 1, i + 1);
    board[v[i].first][v[i].second] = 0;
    board[v[i].first][v[i].second + 1] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> H;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    board[a][b] = 1;
    board[a][b + 1] = -1;
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= N - 1; j++) {
      if (board[i][j] == 0 && board[i][j + 1] == 0) {
        v.push_back({i, j});
      }
    }
  }

  back_tracking(0, 0);

  if (ans == 99) {
    cout << -1;
  } else {
    cout << ans;
  }
}
