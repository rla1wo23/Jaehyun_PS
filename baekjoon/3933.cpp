#include <algorithm>
#include <iostream>
using namespace std;
int ans = 0;
int target = 0;
void lagrangian(int k, int now, int maximum, int last) {
  if (k == maximum) {
    if (now == target) {
      ans++;
    }
    return;
  }
  for (int i = last; i * i <= target - (maximum - 1); i++) {
    int turn = i * i;
    int next = now + turn;
    if (next > target)
      return;
    lagrangian(k + 1, next, maximum, i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    ans = 0;
    cin >> target;
    if (target == 0) {
      return 0;
    }
    for (int i = 1; i <= 4; i++)
      lagrangian(0, 0, i, 1);
    cout << ans << "\n";
  }
}