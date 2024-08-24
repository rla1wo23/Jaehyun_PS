#include <algorithm>
#include <iostream>
using namespace std;
int arr[500005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  sort(arr, arr + N);
  cin >> M;
  while (M--) {
    int k;
    cin >> k;
    cout << upper_bound(arr, arr + N, k) - lower_bound(arr, arr + N, k) << " ";
  }
}