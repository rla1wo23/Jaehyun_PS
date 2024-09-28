#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int K, N;
  cin >> K >> N;
  vector<long long> v(K);
  long long st = 1;
  long long en = 0;
  for (int i = 0; i < K; i++) {
    cin >> v[i];
    en = max(en, v[i]);
  }
  long long ans = 0;
  while (st <= en) {
    long long mid = (st + en) / 2;
    long long cnt = 0;
    for (int i = 0; i < K; i++) {
      cnt += v[i] / mid;
    }
    if (cnt >= N) {
      st = mid + 1;
      ans = mid;
    } else {
      en = mid - 1;
    }
  }
  cout << ans;
}
