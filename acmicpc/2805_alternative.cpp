#include <algorithm>
#include <iostream>
using namespace std;
long long arr[1000001];
int main() {
  long long N, M;
  cin >> N >> M;
  long long low = 0;
  long long high = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (high < arr[i]) {
      high = arr[i];
    }
  }
  long long target = (low + high) / 2;
  long long ans = 0;
  while (low <= high) {
    target = (low + high) / 2;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      if (arr[i] - target > 0) {
        sum += arr[i] - target;
      }
      if (sum > M) {
        break;
      }
    }
    if (sum >= M) {
      ans = target;
      low = target + 1;
    } else { //
      high = target - 1;
    }
  }
  cout << ans << "\n";
}