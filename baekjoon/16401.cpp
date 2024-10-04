// 과자 최대길이랑, 0 사이의 범위로 이분탐색을 할거다.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long M, N;
  cin >> M >> N;
  vector<long long> snacks(N);
  for (int i = 0; i < N; i++) {
    cin >> snacks[i];
  }
  long long ans = 0;
  long long st = 1;
  long long en = 1000000000;
  while (st <= en) {
    long long mid = (st + en) / 2;
    long long sum = 0;
    for (int i = 0; i < snacks.size(); i++) {
      sum += snacks[i] / mid;
      if (sum >= M) {
        break;
      }
    }
    if (sum >= M) {
      ans = max(mid, ans);
      st = mid + 1;
    } else {
      en = mid - 1;
    }
  }
  cout << ans;
}