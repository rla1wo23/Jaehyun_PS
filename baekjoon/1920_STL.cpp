#include <algorithm>
#include <iostream>
using namespace std;
int N;
int arr[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  int M;
  cin >> M;
  sort(arr, arr + N);
  while (M--) {
    int k;
    cin >> k;
    cout << binary_search(arr, arr + N, k) << "\n";
  }
}