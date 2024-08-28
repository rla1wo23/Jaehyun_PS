#include <iostream>
#define X first
#define Y second
using namespace std;
pair<int, int> range[4][2]; // 0은 원점에 더 가까운거, 1은 먼거
bool second_scan(int x, int y) {
  // 2사분면으로 거리 만들기 만약 불가능하면 0 리턴
  if (range[1][0].Y <= y && range[1][1].Y >= y) {
    return true;
  }
  return false;
}
bool can3(int x, int y, int dist) {
  int cx = x - dist;
  int cy = y - dist;
  int small_x = range[2][1].X;
  int large_x = range[2][0].X;
  int small_y = range[2][1].Y;
  int large_y = range[2][0].Y;
  if (cx >= small_x && cx <= large_x && cy >= small_y && cy <= large_y) {
    return true;
  }
  return false;
}
bool can4(int x, int y, int dist) {
  if (range[3][0].X <= x && range[3][1].X >= x) {
    if (range[3][1].Y <= y - dist && range[3][0].Y >= y - dist) {
      return true;
    }
  }
  return false;
}

int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      int x, y;
      cin >> x >> y;
      range[i][j] = {x, y};
    }
  }
  int ans = 0;
  for (int x = range[0][0].X; x <= range[0][1].X; x++) {
    for (int y = range[0][0].Y; y <= range[0][1].Y; y++) {
      if (second_scan(x, y)) {
        int dist;
        int st = -1 * range[1][0].X;
        int en = -1 * range[1][1].X;
        for (; st <= en; st++) {
          dist = x + st;
          if (can3(x, y, dist) && can4(x, y, dist)) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << "\n";
}