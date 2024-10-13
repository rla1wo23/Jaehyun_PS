#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> adj(N + 1);
  for (int i = 1; i <= N; i++) {
    int u;
    cin >> u;
    while (true) {
      int v, c;
      cin >> v;
      if (v == -1)
        break;
      cin >> c;
      adj[u].push_back({v, c});
    }
  }
  bool vis[100005];
  int dist[100005];
  for (int i = 1; i <= N; i++) {
    vis[i] = false;
    dist[i] = 0;
  }
  dist[1] = 0;
  vis[1] = true;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i].first;
      int cost = adj[cur][i].second;
      if (vis[nxt] == true)
        continue;
      vis[nxt] = true;
      q.push(nxt);
      dist[nxt] = dist[cur] + cost;
    }
  }
  int max_cost = 0;
  int max_node = 1;
  for (int i = 2; i <= N; i++) {
    if (max_cost < dist[i]) {
      max_cost = dist[i];
      max_node = i;
    }
  }
  for (int i = 1; i <= N; i++) {
    vis[i] = false;
    dist[i] = 0;
  }
  dist[max_node] = 0;
  vis[max_node] = true;
  q.push(max_node);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i].first;
      int cost = adj[cur][i].second;
      if (vis[nxt] == true)
        continue;
      vis[nxt] = true;
      q.push(nxt);
      dist[nxt] = dist[cur] + cost;
    }
  }
  max_cost = 0;
  for (int i = 1; i <= N; i++) {
    if (max_cost < dist[i]) {
      max_cost = dist[i];
    }
  }
  cout << max_cost;
}