#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  unordered_map<int, int> um;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    um[k] = 1;
  }
  int M;
  cin >> M;
  while (M--) {
    int k;
    cin >> k;
    cout << um[k] << "\n";
  }
}