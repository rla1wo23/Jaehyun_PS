#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int N, M;
int arr[500005];

int lower_idx(int target) {
  int st = 0;
  int en = N;
  while (st < en) {
    int mid = (st + en) / 2;
    if (arr[mid] >= target) // 같으면 점점 en이 내려오기
      en = mid;
    else
      st = mid + 1;
  }
  return st;
}
int upper_idx(int target) {
  int st = 0;
  int en = N;
  while (st < en) {
    int mid = (st + en) / 2;
    if (arr[mid] > target) // 같으면 st가 점점 올라오기
      en = mid;
    else
      st = mid + 1;
  }
  return st;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  sort(arr, arr + N);
  cin >> M;
  for (int j = 0; j < M; j++) {
    int k;
    cin >> k;
    cout << upper_idx(k) - lower_idx(k) << " ";
  }
}