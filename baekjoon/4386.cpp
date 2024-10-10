#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> edges;

int anc[105];
int find(int k) {
  if (anc[k] == k)
    return k;
  return anc[k] = find(anc[k]);
}
void un(int a, int b) {
  if (a > b)
    swap(a, b);
  int anc_of_a = find(a);
  int anc_of_b = find(b);
  if (anc_of_a == anc_of_b)
    return;
  anc[anc_of_b] = anc_of_a;
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    stars.push_back({x, y});
  }
  for (int i = 0; i < N; i++) {
    anc[i] = i;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      pair<double, double> fs = stars[i];
      pair<double, double> ss = stars[j];
      double dif =
          sqrt(pow(fs.first - ss.first, 2) + pow(fs.second - ss.second, 2));
      edges.push_back({dif, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());
  double ans = 0;
  for (int i = 0; i < edges.size(); i++) {
    int x = edges[i].second.first;
    int y = edges[i].second.second;
    if (find(x) == find(y))
      continue;
    un(x, y);
    ans += edges[i].first;
  }
  cout << ans;
}