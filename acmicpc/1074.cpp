#include <cmath>
#include <iostream>
using namespace std;
long long r, c;
void division(long long N, long long cnt) {
  if (N == 0) {
    cout << cnt;
    return;
  } else {
    long long div = pow(2, N - 1); // 행 또는 열의 너비
    long long sum = pow(4, N - 1); // 디비전의 크기
    if (r < div) {                 // 1,2사분면
      if (c < div) {               // 2사분면, 누적 x
        division(N - 1, cnt);
      } else {
        c -= div;
        division(N - 1, cnt + sum);
      }
    } else {         // 3,4사분면
      if (c < div) { // 3사분면
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
  long long N;
  cin >> N >> r >> c;
  division(N, 0);
}
