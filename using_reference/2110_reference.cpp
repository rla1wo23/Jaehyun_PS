#include <algorithm>
#include <iostream>
using namespace std;
int house[200005];
int N, C;
bool can_build(int dist) {
  int cnt = 1;
  int prev = house[0];
  for (int i = 1; i < N; i++) {
    if (dist <= house[i] - prev) {
      cnt++;
      prev = house[i];
    }
  }
  return cnt >= C;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> C;
  for (int i = 0; i < N; i++)
    cin >> house[i];
  sort(house, house + N);
  int st = 1;
  int en = house[N - 1] - house[0];
  int ans = 0;
  while (st <= en) {
    int dist = (st + en) / 2;
    if (can_build(dist)) {
      ans = max(dist, ans);
      st = dist + 1;
    } else {
      en = dist - 1;
    }
  }
  cout << ans;
}