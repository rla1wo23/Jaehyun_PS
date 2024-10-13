#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int N;
long long dp[105][105];
long long board[105][105];
long long dx[2] = {1, 0};
long long dy[2] = {0, 1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  stack<pair<int, int>> s;
  s.push({0, 0});
  dp[0][0] = 1;
  while (!s.empty()) {
    int curx = s.top().first;
    int cury = s.top().second;
    int value = board[curx][cury];
    s.pop();
    if (value <= 0)
      continue;
    for (int i = 0; i < 2; i++) {
      int nx = curx + dx[i] * value;
      int ny = cury + dy[i] * value;
      if (nx >= N || ny >= N)
        continue;
      dp[nx][ny] += dp[curx][cury];
      s.push({nx, ny});
    }
  }
  cout << dp[N - 1][N - 1];
}