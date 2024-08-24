#include <iostream>
using namespace std;

long long dp[12] = {0};
int fib(int n) {
  if (dp[n] != 0 || n == 0) {
    return dp[n];
  } else {
    return dp[n] = fib(n - 1) + fib(n - 2) + fib(n - 3);
  }
}
int main() {
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (dp[n] != 0) {
      cout << dp[n];
    } else {
      cout << fib(n);
    }
    cout << "\n";
  }
}
