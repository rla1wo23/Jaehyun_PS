#include <iostream>
using namespace std;
int calc(int st, int en) {
  if ((st + en) % 2 == 0) { // 홀수길이란 뜻
    return ((st + en) / 2) * (en - st + 1);
  } else {
    return (st + en) * (en - st + 1) / 2;
  }
}
int mem[1000005] = {0};
int main() {
  while (true) {
    int N;
    cin >> N;
    if (N == 0)
      return 0;
    if (mem[N] != 0) {
      cout << mem[N] << "\n";
      continue;
    }
    int ans = 0;
    int st = 2;
    int en = 2;
    while (st <= en && st <= N) {
      if (calc(st, en) == N) {
        ans++;
        st++;
      } else if (calc(st, en) <= N) {
        en++;
      } else {
        st++;
      }
    }
    cout << ans << "\n";
    mem[N] = ans;
  }
}