#include <algorithm>
#include <iostream>
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
  int cnt = 1;
  int ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    ans = max(ans, v[i] * cnt);
    cnt++;
  }
  cout << ans;
}