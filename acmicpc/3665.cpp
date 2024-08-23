#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> adj(n + 1);
    int degree[501] = {0};
    int arr[501] = {0}; // 원래 team과 등수(index가 팀, i가 등수)
    bool changed[501][501] = {false};
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      arr[v[i]] = i;
    }
    int m;
    cin >> m;
    while (m--) {
      int a, b;
      cin >> a >> b;
      changed[a][b] = true;
      changed[b][a] = true;
      if (arr[a] < arr[b]) { // 원래 a가 등수가 더 높았다면
        adj[b].push_back(a);
        degree[a]++;
      } else {
        adj[a].push_back(b);
        degree[b]++;
      }
    }
    for (int i = 1; i <= n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (!changed[v[i]][v[j]]) {
          adj[i].push_back(j);
          degree[j]++;
        }
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (degree[i] == 0) {
        q.push(i);
      }
    }
    queue<int> ans;
    while (!q.empty()) {
      if (q.size() > 1) {
        break;
      }
      int cur = q.front();
      q.pop();
      ans.push(cur);
      for (int nxt : adj[cur]) {
        degree[nxt]--;
        if (degree[nxt] == 0) {
          q.push(nxt);
        }
      }
    }
    if (!q.empty()) {
      cout << "?\n";
    } else if (ans.size() == n) {
      while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
      }
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
}