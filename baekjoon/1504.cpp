#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, E;
const int INF = 0x3f3f3f3f;
int main() {
  cin >> N >> E;
  vector<vector<pair<int, int>>> adj(N + 1); // 비용,목적지
  for (int i = 0; i < E; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({c, v});
    adj[v].push_back({c, u});
  }
  int p1, p2;
  cin >> p1 >> p2;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q[3];
  int target[3] = {1, p1, p2};
  int dist[3][805];
  for (int t = 0; t < 3; t++) {
    dist[t][target[t]] = 0;
    for (int i = 2; i <= N; i++) {
      dist[t][i] = INF;
    }
    dist[t][target[t]] = 0;
    q[t].push({0, target[t]});
    while (!q[t].empty()) {
      pair<int, int> cur = q[t].top();
      q[t].pop();
      if (dist[t][cur.second] != cur.first)
        continue;
      for (auto nxt : adj[cur.second]) {
        if (dist[t][nxt.second] > cur.first + nxt.first) {
          q[t].push({cur.first + nxt.first, nxt.second});
          dist[t][nxt.second] = cur.first + nxt.first;
        }
      }
    }
  }
  int ansA = dist[0][p1] + dist[1][p2] + dist[2][N];
  int ansB = dist[0][p2] + dist[2][p1] + dist[1][N];
  if (dist[0][N] == INF || dist[0][p1] == INF || dist[0][p2] == INF) {
    cout << -1;
    return 0;
  }
  cout << min(ansA, ansB);
}