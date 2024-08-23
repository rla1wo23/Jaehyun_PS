#include <iostream>
#include <queue>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N + 1);
  vector<int> degree(N + 1);
  for (int i = 0; i < M; i++) {
    int n, a;
    cin >> n >> a;
    for (int j = 1; j < n; j++) {
      int b;
      cin >> b;
      adj[a].push_back(b);
      a = b;
      degree[b]++;
    }
  }
  queue<int> a;
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (degree[i] == 0) {
      q.push(i);
      a.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adj[cur].size(); i++) {
      degree[adj[cur][i]]--;
      if (degree[adj[cur][i]] == 0) {
        q.push(adj[cur][i]);
        a.push(adj[cur][i]);
      }
    }
  }
  if (a.size() != N) {
    cout << 0;
    return 0;
  }
  while (!a.empty()) {
    cout << a.front() << "\n";
    a.pop();
  }
}