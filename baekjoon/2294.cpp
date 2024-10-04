#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dp[10005];
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<int>());
  queue<int> q;
  for (int i = 0; i < N; i++) {
    q.push(0);
  }
  for (int i = 0; i <= K; i++) {
    dp[i] = INF;
  }
  dp[0] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == K) {
      cout << dp[K];
      return 0;
    }
    for (int i = 0; i < N; i++) {
      int nxt = cur + v[i];
      if (nxt <= K) {
        if (dp[nxt] > dp[cur] + 1) {
          dp[nxt] = min(dp[nxt], dp[cur] + 1);
          q.push(nxt);
        }
      }
    }
  }
  cout << -1;
}