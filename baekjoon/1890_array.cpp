#include <algorithm>
#include <iostream>
using namespace std;
int N;
long long dp[105][105];
long long board[105][105];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i][j] == 0 || (i == N - 1 && j == N - 1))
        continue;
      for (int dir = 0; dir < 2; dir++) {

        int nx = i + dx[dir] * board[i][j];
        int ny = j + dy[dir] * board[i][j];
        if (nx >= N || ny >= N)
          continue;
        dp[nx][ny] += dp[i][j];
      }
    }
  }
  cout << dp[N - 1][N - 1];
}