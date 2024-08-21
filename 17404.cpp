#include <algorithm>
#include <iostream>
using namespace std;
int dp[3][1005] = {0};
int street[3][1005] = {0};
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> street[0][i] >> street[1][i] >> street[2][i];
  }
  // R G로 끝나기
  for (int i = 1; i <= N - 1; i++) {
    dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + street[0][i];
    dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + street[1][i];
    dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + street[2][i];
  }
  cout << min(min(dp[0][N], dp[1][N]), dp[2][N]);
}