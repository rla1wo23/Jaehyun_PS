#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  unordered_set<int> sum_set;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      sum_set.insert(v[i] + v[j]);
    }
  }
  int ans = 0;
  for (int k = N - 1; k >= 0; k--) {
    for (int i = 0; i < N; i++) {
      int diff = v[k] - v[i];
      if (sum_set.count(diff)) {
        ans = max(ans, v[k]);
      }
    }
  }
  cout << ans;
}
