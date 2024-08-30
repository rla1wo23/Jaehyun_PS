#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
int N;
int board[15][15];
int ans1 = 0, ans2 = 0;
bool check(int x, int y) {
  for (int i = 1; i < N; i++) {
    if (x + i < N && y + i < N && board[x + i][y + i] == 2) {
      return false;
    }
    if (x - i >= 0 && y + i < N && board[x - i][y + i] == 2) {
      return false;
    }
    if (x - i >= 0 && y - i >= 0 && board[x - i][y - i] == 2) {
      return false;
    }
    if (x + i < N && y - i >= 0 && board[x + i][y - i] == 2) {
      return false;
    }
  }
  return true;
}
void combination1(int idx, int cur) {
  if (idx >= v1.size()) {
    return;
  }
  for (int i = idx; i < v1.size(); i++) {
    if (check(v1[i].first, v1[i].second)) {
      cur++;
      ans1 = max(ans1, cur);
      board[v1[i].first][v1[i].second] = 2;
      combination1(i + 1, cur);
      board[v1[i].first][v1[i].second] = 0;
      cur--;
    }
  }
}
void combination2(int idx, int cur) {
  if (idx >= v2.size()) {
    return;
  }
  for (int i = idx; i < v2.size(); i++) {
    if (check(v2[i].first, v2[i].second)) {
      cur++;
      ans2 = max(ans2, cur);
      board[v2[i].first][v2[i].second] = 2;
      combination2(i + 1, cur);
      board[v2[i].first][v2[i].second] = 0;
      cur--;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int n;
      cin >> n;
      if (n == 1) {
        if ((i + j) % 2 == 0) {
          v1.push_back({i, j});
        } else {
          v2.push_back({i, j});
        }
      }
    }
  }
  combination1(0, 0);
  combination2(0, 0);
  cout << ans1 + ans2;
}