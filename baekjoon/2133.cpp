#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int max_tiles;

int main() {
  cin >> N;
  if (N % 2 == 1) {
    cout << 0;
    return 0;
  } else {
    max_tiles = (3 * N) / 2;
  }
}
