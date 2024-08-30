#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<pair<int, int>> v;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), compare);
  int d;
  cin >> d;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (v[i].second - v[i].first > d)
      continue;
    if (pq.empty()) {
      pq.push(v[i]);
    } else {
      while (!pq.empty() && v[i].second - pq.top().first > d) {
        pq.pop();
      }
      pq.push(v[i]);
    }
    ans = max(ans, int(pq.size()));
  }
  cout << ans;
}