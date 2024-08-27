#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<vector<pair<int, int>>> adj;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  adj.resize(N + 1);
  while (M--) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({c, v});
  }
  int st, en;
  cin >> st >> en;
  int city[1005] = {0};
  for (int i = 1; i <= N; i++) {
    city[i] = INF;
  }
  city[st] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.push({0, st});
  while (!q.empty()) {
    int cost = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (city[cur] != cost)
      continue;
    for (auto nxt : adj[cur]) {
      if (cost + nxt.first < city[nxt.second]) {
        city[nxt.second] = cost + nxt.first;
        q.push({city[nxt.second], nxt.second});
      }
    }
  }
  cout << city[en];
}