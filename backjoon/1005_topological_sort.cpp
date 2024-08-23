#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> adj(N + 1);
    int indegree[1005] = {0};
    int value[1005] = {0};
    int ans_table[1005] = {0};
    for (int i = 1; i <= N; i++) {
      cin >> value[i];
    }
    while (K--) {
      int X, Y;
      cin >> X >> Y;
      adj[X].push_back(Y);
      indegree[Y]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
      ans_table[i] = value[i];
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    int w;
    cin >> w;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur == w) {
        cout << ans_table[w] << "\n";
        break;
      }
      for (int i = 0; i < adj[cur].size(); i++) {
        int adj_node = adj[cur][i];
        indegree[adj_node]--;
        ans_table[adj_node] =
            max(ans_table[adj_node], value[adj_node] + ans_table[cur]);
        if (indegree[adj_node] == 0) {
          q.push(adj_node);
        }
      }
    }
  }
}