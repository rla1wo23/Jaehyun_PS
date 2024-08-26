#include <algorithm>
#include <iostream>
using namespace std;
int dp[1000001][2];
vector<vector<int>> adj;
void dfs(int cur, int par) {
  dp[cur][0] = 0;
  dp[cur][1] = 1;
  bool is_leaf = true;
  for (int i = 0; i < adj[cur].size(); i++) {
    int child = adj[cur][i];
    if (child == par)
      continue;
    is_leaf = false;
    dfs(child, cur);
    dp[cur][0] += dp[child][1];
    dp[cur][1] += min(dp[child][0], dp[child][1]);
  }
}
int main() {
  int N;
  cin >> N;
  adj.resize(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << min(dp[1][0], dp[1][1]);
}