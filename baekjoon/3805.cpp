#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int n, m;

int bfs(int start,) {
  vector<int> dist(n, -1); // 각 노드의 거리를 저장
  queue<pair<int, int>> q; // {노드, 부모 노드}

  dist[start] = 0;
  q.push({start, -1});
  int min_cycle = 505;

  while (!q.empty()) {
    int cur = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (int nxt : adj[cur]) {
      if (nxt == parent)
        continue;            // 부모 노드로 되돌아가는 것은 제외
      if (dist[nxt] == -1) { // 처음 방문하는 노드
        dist[nxt] = dist[cur] + 1;
        q.push({nxt, cur});
        visited[nxt] = true;
      } else { // 이미 방문한 노드이면 사이클 발견
        min_cycle = min(min_cycle, dist[cur] + dist[nxt] + 1);
      }
    }
  }

  return min_cycle;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    cin >> n >> m;
    adj.clear();
    adj.resize(n);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int ans = 505;
    vector<bool> visited(n, false);
    for (int node = 0; node < n; node++) {
      if (!visited[node]) {
        visited[node] = true;
        ans = min(ans, bfs(node));
      }
    }
    cout << "Case " << tc << ": ";
    if (ans == 505) {
      cout << "impossible\n";
    } else {
      cout << ans << "\n";
    }
  }
}
