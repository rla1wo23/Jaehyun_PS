#include <iostream>
using namespace std;

long long calc(long long n) {
  long long ans = n;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
int main() {
  long long N;
  cin >> N;
  for (long long i = N - 162; i < N; i++) {
    if (calc(i) == N) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
}