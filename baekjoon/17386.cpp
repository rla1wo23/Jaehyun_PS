#include <algorithm>
#include <iostream>
using namespace std;

double inc(double x1, double y1, double x2, double y2, double x3, double y3) {
  return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int main() {
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  // 더 일찍 끝나는 쪽부터
  double x3, y3, x4, y4;
  cin >> x3 >> y3 >> x4 >> y4;
  if (x3 > x4) {
    swap(x3, x4);
    swap(y3, y4);
  }
  // x1이 더 먼저 끝나는거다.
  if (x2 > x4) {
    swap(x1, x3);
    swap(y1, y3);
    swap(x2, x4);
    swap(y2, y4);
  }
  // under인지 over인지 먼저 판별
  double c1 = inc(x1, y1, x2, y2, x3, y3);
  double c2 = inc(x1, y1, x2, y2, x4, y4);
  double c3 = inc(x3, y3, x4, y4, x1, y1);
  double c4 = inc(x3, y3, x4, y4, x2, y2);

  if (c1 * c2 < 0 && c3 * c4 < 0) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}
