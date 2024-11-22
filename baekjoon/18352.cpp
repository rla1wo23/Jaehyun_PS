#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, K, X;
  cin >> N >> M >> K >> X;
  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  int dist[300005];
  bool vis[300005];
  for (int i = 1; i <= N; i++) {
    dist[i] = 0x3f3f3f3f;
    vis[i] = false;
  }
  dist[X] = 0;
  vis[X] = true;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, X});
  while (!pq.empty()) {
    int cur = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    for (int i = 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i];
      if (!vis[nxt]) {
        dist[nxt] = cost + 1;
        vis[nxt] = true;
        pq.push({cost + 1, nxt});
      }
    }
  }
  bool btn = false;
  for (int i = 1; i <= N; i++) {
    if (dist[i] == K) {
      cout << i << "\n";
      btn = true;
    }
  }
  if (!btn) {
    cout << -1;
  }
}