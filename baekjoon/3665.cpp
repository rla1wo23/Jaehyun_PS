#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    bool changed[505][505];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        changed[i][j] = false;
      }
    }
    vector<int> rank(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> rank[i];
    }
    vector<pair<int, int>> changed_list;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      changed[u][v] = true; // u가 더 높은거다
    }
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1);
    for (int i = 1; i <= n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
        int u = rank[i];
        int v = rank[j];
        if (changed[u][v] || changed[v][u]) {
          swap(u, v);
        }
        degree[v]++;
        adj[u].push_back(v);
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (degree[i] == 0) {
        q.push(i);
      }
    }
    queue<int> ans_queue;
    int ans_cnt = 0;
    bool err_flag = false;
    while (!q.empty()) {
      if (q.size() > 1) {
        err_flag = true;
      }
      int cur = q.front();
      q.pop();
      ans_cnt++;
      ans_queue.push(cur);
      for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        degree[nxt]--;
        if (degree[nxt] == 0)
          q.push(nxt);
      }
    }
    if (ans_cnt != n) {
      cout << "IMPOSSIBLE\n";
    } else if (err_flag) {
      cout << "?\n";
    } else {
      while (!ans_queue.empty()) {
        cout << ans_queue.front() << " ";
        ans_queue.pop();
      }
      cout << "\n";
    }
  }
}