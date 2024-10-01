#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> edges(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edges[u].push_back({c, v});
  }
  int st, en;
  cin >> st >> en;
  int pre[1005];
  bool done[1005];
  int cost[1005];
  for (int i = 0; i <= n; i++) {
    pre[i] = INF;
    done[i] = false;
    cost[i] = INF;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, st});
  pre[st] = 0;
  cost[st] = 0;
  while (!pq.empty()) {
    int cur_cost = pq.top().first;
    int cur_pos = pq.top().second;
    pq.pop();
    if (cur_cost != cost[cur_pos])
      continue;
    for (int i = 0; i < edges[cur_pos].size(); i++) {
      int nxt_cost = edges[cur_pos][i].first + cur_cost;
      int nxt = edges[cur_pos][i].second;
      if (done[nxt])
        continue;
      if (nxt_cost < cost[nxt]) {
        pq.push({nxt_cost, nxt});
        cost[nxt] = nxt_cost;
        pre[nxt] = cur_pos;
      }
    }
  }
  stack<int> s;
  int cur = en;
  while (cur != 0) {
    s.push(cur);
    cur = pre[cur];
  }
  cout << cost[en] << "\n";
  cout << s.size() << "\n";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}