#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double X;
  cin >> X;
  int cnt = 0;

  for (long long i = 1; i < 1e8; i++) {
    if (i * X != floor(i * X))
      continue;
    long long num = i;
    long long t = 10;
    while (t < i) {
      t *= 10;
    }
    t /= 10;
    long long mok = i / t;
    num -= mok * t;
    num *= 10;
    num += mok;
    if (num == i * X) {
      cout << i << "\n";
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << "No solution";
  }
}