#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  vector<int> adj;
  int subtree_size = 1;
};
node nodes[100005];
bool visited[100005];
int dfs(int R) {
  visited[R] = true;
  int tmp = 1;
  for (int i = 0; i < nodes[R].adj.size(); i++) {
    if (visited[nodes[R].adj[i]])
      continue;
    tmp += dfs(nodes[R].adj[i]);
  }
  return nodes[R].subtree_size = tmp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, R, Q;
  cin >> N >> R >> Q;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    nodes[u].adj.push_back(v);
    nodes[v].adj.push_back(u);
  }
  dfs(R);
  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    cout << nodes[q].subtree_size << "\n";
  }
}