#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  int beat[100][100];
  while (T--) {
    int win[100] = {
        0,
    };
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        beat[i][j] = 0;
      }
    }
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
      int A, B;
      cin >> A >> B;
      A--;
      B--;
      beat[A][B] = 1;
      win[A]++;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          if (beat[k][i] && beat[i][j] && beat[k][j] == 0) {
            beat[k][j] = 1;
            win[k]++;
          }
        }
      }
    }
    for (int i = 0; i < N; i++) {
      cout << win[i] << " ";
    }
    cout << "\n";
  }
}