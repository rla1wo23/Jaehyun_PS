#include <algorithm>
#include <iostream>
using namespace std;
// 해당 칸에 진입할 때의 최대 값 구함 됨
int main() {
  int N;
  cin >> N;
  int x, y, z; // 큰거 저장
  cin >> x >> y >> z;
  int mx = x, my = y, mz = z; // 작은거 저장
  for (int i = 1; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int nx, ny, nz;
    int nmx, nmy, nmz;
    nx = max(x, y) + a;
    ny = max(max(x, y), z) + b;
    nz = max(y, z) + c;
    x = nx;
    y = ny;
    z = nz;
    nmx = min(mx, my) + a;
    nmy = min(min(mx, my), mz) + b;
    nmz = min(my, mz) + c;
    mx = nmx;
    my = nmy;
    mz = nmz;
  }
  cout << max(max(x, y), z) << " " << min(min(mx, my), mz);
}