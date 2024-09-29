#include <algorithm>
#include <iostream>
using namespace std;
int N;
int ans = 0;
void back_tracking(int k, long long before) {
  if (k == N) {
    if (before % 3 == 0) {
      ans++;
    }
  } else {
    for (int i = 0; i < 3; i++) {
      if (i == 0 && k == 0)
        continue;
      back_tracking(k + 1, before * 10 + i);
    }
  }
}
int main() {
  cin >> N;
  back_tracking(0, 0);
  cout << ans;
}