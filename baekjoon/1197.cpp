#include <algorithm>
#include <iostream>
using namespace std;
int vertices[10005];
pair<int, pair<int, int>> edges[100005];
int V, E;
int ans = 0;

int find(int k) {
  if (k == vertices[k])
    return k;
  return vertices[k] = find(vertices[k]);
}
void un(int a, int b) {
  if (a > b)
    swap(a, b);
  vertices[find(b)] = vertices[find(a)];
  vertices[b] = vertices[a];
}
void init() {
  cin >> V >> E;
  for (int i = 1; i <= V; i++) {
    vertices[i] = i;
  }
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[i] = {c, {a, b}};
  }
}
void mst() {
  sort(edges, edges + E);
  for (int i = 0; i < E; i++) {
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    if (find(a) == find(b))
      continue;
    un(a, b);
    ans += edges[i].first;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  mst();
  cout << ans;
}