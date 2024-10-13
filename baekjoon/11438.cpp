#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parents[100005];
int depth[100005];
bool vis[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i];
      if (vis[nxt])
        continue;
      vis[nxt] = true;
      depth[nxt] = depth[cur] + 1;
      parents[nxt] = cur;
      q.push(nxt);
    }
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    if (depth[u] < depth[v]) // u가 더 깊어야함
      swap(u, v);
    while (depth[u] != depth[v]) {
      u = parents[u];
    }
    while (u != v) {
      u = parents[u];
      v = parents[v];
    }
    cout << u << "\n";
  }
}