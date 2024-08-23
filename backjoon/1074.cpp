#include <cmath>
#include <iostream>
using namespace std;
int r, c;
void division(int N, int cnt) {
  if (N == 0) {
    cout << cnt;
    return;
  } else {
    int div = pow(2, N - 1);
    int sum = pow(4, N - 1);
    if (r < div) {
      if (c < div) {
        division(N - 1, cnt);
      } else {
        c -= div;
        division(N - 1, cnt + sum);
      }
    } else {
      if (c < div) {
        r -= div;
        division(N - 1, cnt + sum * 2);
      } else {
        r -= div;
        c -= div;
        division(N - 1, cnt + sum * 3);
      }
    }
  }
}
int main() {
  int N;
  cin >> N >> r >> c;
  division(N, 0);
}