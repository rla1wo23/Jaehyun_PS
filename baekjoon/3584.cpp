#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int parents[10000];
    for (int i = 0; i < N; i++) {
      parents[i] = -1;
    }
    for (int i = 0; i < N - 1; i++) {
      int A, B;
      cin >> A >> B;
      parents[B] = A;
    }
    int lc, rc;
    cin >> lc >> rc;
    int tg = lc;
    unordered_map<int, int> um;
    while (tg != -1) {
      um[tg] = 1;
      tg = parents[tg];
    }
    while (um[rc] == 0) {
      rc = parents[rc];
    }
    cout << rc << "\n";
  }
}
