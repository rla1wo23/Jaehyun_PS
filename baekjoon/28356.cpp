#include <algorithm>
#include <iostream>
using namespace std;
int board[1005][1005];
int N, M;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  if (N == 1) {
    cout << min(M, 2) << "\n";
  } else if (M == 1) {
    cout << min(N, 2) << "\n";
  } else {
    cout << min(N * M, 4) << "\n";
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          cout << 1 << " ";
        } else {
          cout << 2 << " ";
        }
      } else {
        if (j % 2 == 0) {
          if (M == 1) {
            cout << 2 << " ";
          } else {
            cout << 3 << " ";
          }
        } else {
          cout << 4 << " ";
        }
      }
    }
    cout << "\n";
  }
}