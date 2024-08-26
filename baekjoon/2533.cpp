// 리프노드의 부모노드들은 다 칠해야 한다.
// 색칠된 노드는, 자식에서 빼야 하고, 뺀 다음에 내가 리프노드가 된다면 내
// 부모노드 역시 색칠돼야 한다.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj; // 자기 부모만 제외하고 순회 가능
bool colored[1000001] = {false};
int ans = 0;
bool dfs(int cur, int par) { // 해당 노드가 리프라면 색칠한다.
  for (int i = 0; i < adj[cur].size(); i++) {
    int nxt = adj[cur][i];
    if (nxt == par) { // 부모는 방문하지 않는다.
      continue;
    } else {
      if (dfs(nxt, cur) == true) {
        adj[cur].erase(adj[cur].begin() + i);
        if (colored[nxt] == false) {
          if (colored[cur] !=
              true) { // 색칠되지 않은 노드의 부모라면, 반드시 칠해야 한다.
            ans++;
          }
          colored[cur] = true;
        }
        i--;
      }
    }
  }
  return adj[cur].size() == 1; // size가 1이라면 true를
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  adj.resize(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  int cnt = 0;
  cout << ans;
}
