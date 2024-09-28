#include <iostream>
using namespace std;

int main() {
  int X1, X2, m, Seed;
  cin >> m >> Seed;
  cin >> X1 >> X2;
  for (int a = 0; a < m; a++) {
    for (int c = 0; c < m; c++) {
      if ((a * Seed + c) % m == X1) {
        if ((a * X1 + c) % m == X2) {
          cout << a << " " << c;
        }
      }
    }
  }
}