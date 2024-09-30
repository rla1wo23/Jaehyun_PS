#include <iostream>
using namespace std;

int main() {
  long long K;
  cin >> K;
  if (K < 0) {
    K = -K;
  }
  if (K == 0) {
    cout << 0;
    return 0;
  }
  if (K % 2 == 0) {
    cout << -1;
    return 0;
  }

  long long c = 1;
  long long cnt = 1;
  K++;
  long long s = 1;
  while (s < 1e13) {
    s *= 2;
    if (s == K) {
      cout << cnt;
      return 0;
    }
    cnt++;
  }
  cout << -1;
  return 0;
}
