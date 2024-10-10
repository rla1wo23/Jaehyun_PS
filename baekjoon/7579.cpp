#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int bytes[105];
  int costs[105];
  int dp[10005];
  for (int i = 0; i < 10005; i++) {
    dp[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> bytes[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> costs[i];
    dp[costs[i]] = max(dp[costs[i]], bytes[i]);
  }
  for (int i = 1; i < 10005; i++) {
    if (dp[i] == 0) {
      dp[i] = dp[i - 1];
    }
  }
  for (int i = 0; i <= 10000; i++) { // 비용 i
    for (int idx = 0; i < N; i++) {  // 비용이 i인 idx있는지 검사
    }
  }
}