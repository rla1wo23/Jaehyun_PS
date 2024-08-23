#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<pair<pair<int, int>, int>> edges;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second < b.second;
}
int par[100005] = {0};
int find(int k) {
  if (k == par[k]) {
    return k;
  }
  return par[k] = find(par[k]);
}
void uni(int a, int b) {
  if (par[a] < par[b]) {
    par[find(par[b])] = find(par[a]);
  }
  par[find(par[a])] = find(par[b]);
}
int solution() {
  int ans = 0;
  sort(edges.begin(), edges.end(), cmp);
  int cnt = 0;
  int idx = 0;
  while (cnt < N - 2 && idx < M) {
    pair<pair<int, int>, int> cur = edges[idx];
    if (find(cur.first.first) != find(cur.first.second)) {
      uni(cur.first.first, cur.first.second);
      ans += cur.second;
      cnt++;
    }
    idx++;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    par[i] = i;
  }
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    edges.push_back({{A, B}, C});
  }
  cout << solution();
}