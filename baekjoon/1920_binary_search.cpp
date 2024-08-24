#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> arr;
int bin_search(int k) {
  int st = 0;
  int en = N - 1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (arr[mid] == k) {
      return 1;
    } else if (arr[mid] < k) {
      st = mid + 1;
    } else {
      en = mid - 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    arr.push_back(k);
  }
  int M;
  cin >> M;
  sort(arr.begin(), arr.end());
  while (M--) {
    int k;
    cin >> k;
    cout << bin_search(k) << "\n";
  }
}