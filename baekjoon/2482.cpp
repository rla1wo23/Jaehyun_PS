#include <iostream>
using namespace std;
int divisor = 1e9 + 3;
int dp[1005][1005];
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    dp[i][1] = i;
  dp[4][2] = 2;
  for (int i = 5; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % divisor;
    }
  }
  cout << dp[n][k];
}