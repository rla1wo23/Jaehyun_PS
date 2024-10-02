#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ingoing_edges[32005];
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    ingoing_edges[v]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 1; i <= N; i++) {
    if (ingoing_edges[i] == 0) {
      pq.push({0, i});
    }
  }
  while (!pq.empty()) {
    int cur = pq.top().second;
    pq.pop();
    cout << cur << " ";
    for (int i = 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i];
      ingoing_edges[nxt]--;
      if (ingoing_edges[nxt] == 0) {
        pq.push({0, nxt});
      }
    }
  }
}