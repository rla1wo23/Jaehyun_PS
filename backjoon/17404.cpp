#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  int N;
  cin >> N;
  int cost[3][1005] = {0};
  for (int i = 0; i < N; i++) {
    cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
  }
  int ans = INF;
  for (int st = 0; st <= 2; st++) {
    int dp[3][1005] = {0};
    for (int i = 0; i <= 2; i++) {
      if (i == st) {
        dp[st][0] = cost[st][0];
      } else {
        dp[i][0] = INF;
      }
    }
    for (int i = 1; i < N - 1; i++) {
      dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
      dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[1][i];
      dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
    }
    for (int i = 0; i <= 2; i++) {
      if (i == st)
        continue;
      dp[i][N - 1] =
          min(dp[(i + 2) % 3][N - 2], dp[(i + 4) % 3][N - 2]) + cost[i][N - 1];
      ans = min(dp[i][N - 1], ans);
    }
  }
  cout << ans;
}