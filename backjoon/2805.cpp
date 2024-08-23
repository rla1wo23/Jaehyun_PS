#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int arr[1000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  int hmax = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  hmax = arr[N - 1];
  int sum = 0;
  int cnt = 0;
  auto addr = upper_bound(arr, arr + N, arr[N - 1]);
  while (sum < M) {
    cnt++;
    sum += addr - lower_bound(arr, arr + N, hmax);
    hmax--;
  }
  cout << arr[N - 1] - cnt << "\n";
}