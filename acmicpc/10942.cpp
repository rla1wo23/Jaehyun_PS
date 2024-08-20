#include <iostream>
#include <vector>
using namespace std;
int arr[2005];
bool dp[2005][2005] = {false};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < N; i++) {
    dp[i][i] = true;
    if (arr[i] == arr[i + 1]) {
      dp[i][i + 1] = true;
    } else {
      dp[i][i + 1] = false;
    }
  }
  dp[N][N] = true;
  for (int i = 2; i <= N; i++) { // palindrome length
    for (int j = 1; j <= N - i + 1; j++) {
      int s = j;
      int e = j + i - 1;
      if (dp[s + 1][e - 1] && arr[s] == arr[e]) {
        dp[s][e] = true;
      }
    }
  }
  int m, s, e;
  cin >> m;
  while (m--) {
    cin >> s >> e;
    cout << dp[s][e] << "\n";
  }
}