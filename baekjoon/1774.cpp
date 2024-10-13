#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int group[1005];
int find(int k) {
  if (k == group[k])
    return k;
  return k = find(group[k]);
}
void un(int a, int b) {
  if (a > b)
    swap(a, b);
  int anc_a = find(a);
  int anc_b = find(b);
  if (anc_a == anc_b)
    return;
  group[anc_b] = anc_a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  unordered_map<int, pair<double, double>> um;
  for (int i = 1; i <= N; i++) {
    double x, y;
    cin >> x >> y;
    um[i] = {x, y};
    group[i] = i;
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    un(a, b);
  }
  vector<pair<double, pair<int, int>>> edges;
  for (int i = 1; i <= N - 1; i++) {
    double ax = um[i].first;
    double ay = um[i].second;
    for (int j = i + 1; j <= N; j++) {
      double bx = um[j].first;
      double by = um[j].second;
      double dif = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
      edges.push_back({dif, {i, j}});
    }
  }
  double ans = 0.0;
  cout << fixed;
  cout.precision(2);
  sort(edges.begin(), edges.end());
  for (int i = 0; i < edges.size(); i++) {
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    if (find(a) == find(b))
      continue;
    un(a, b);
    ans += edges[i].first;
  }
  cout << ans;
}