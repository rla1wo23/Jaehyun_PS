#include <iostream>
using namespace std;
pair<int, int> dp[42];
pair<int, int> fibonacci(int n) {
  if (dp[n].first != 0 || dp[n].second != 0) {
    return dp[n];
  }
  if (n == 0) {
    dp[0] = {1, 0};
    return {1, 0};
  } else if (n == 1) {
    return dp[1] = {0, 1};
  };
  pair<int, int> f1 = fibonacci(n - 1);
  pair<int, int> f2 = fibonacci(n - 2);

  return dp[n] = {f1.first + f2.first, f1.second + f2.second};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    pair<int, int> ans = fibonacci(N);
    cout << ans.first << " " << ans.second << "\n";
  }
}