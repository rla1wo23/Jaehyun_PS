#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), greater<int>());
  int max_idx = 0;
  for (int i = 0; i < N; i++) {
    if (v[i] == 0)
      continue;
    max_idx = max(max_idx, v[i] + i - 1);
  }
  if (v[0] == 0) {
    cout << 0;
  } else {
    if (max_idx + 1 > N) {
      cout << N;
    } else {
      cout << max_idx + 1;
    }
  }
}