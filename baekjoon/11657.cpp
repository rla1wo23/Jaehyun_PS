#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 0x7f7f7f7f;
vector<pair<pair<int, int>, int>> edges;
long long dist[505];
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edges.push_back({{u, v}, c});
  }
  dist[1] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      long long u = edges[j].first.first;  // from
      long long v = edges[j].first.second; // to
      long long c = edges[j].second;
      if (dist[u] == INF)
        continue;
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
      }
    }
  }
  for (int j = 0; j < M; j++) {
    long long u = edges[j].first.first;  // from
    long long v = edges[j].first.second; // to
    long long c = edges[j].second;
    if (dist[u] == INF)
      continue;
    if (dist[v] > dist[u] + c) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (dist[i] == INF) {
      cout << -1 << "\n";
    } else {
      cout << dist[i] << "\n";
    }
  }
}