#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int m;
int dp[200005][6];
int main() {
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> dp[i][1];
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int n, x;
    cin >> n >> x;
    while (x > 5) {
      if (dp[n][5] == 0) {
      }
    }
  }
}