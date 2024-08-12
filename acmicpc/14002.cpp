#include <algorithm>
#include <iostream>
using namespace std;
int N;
int arr[1005];
pair<int, int> dp[1005]; // first는 뒤의 LIS길이
                         // second는 그 수의 인덱스
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  dp[N - 1] = {1, -1};
  pair<int, int> ans = {1, N - 1}; // 최대 길이와, 시작하는 애의 idx를 저장
  for (int i = N - 2; i >= 0; i--) {
    dp[i] = {1, -1};
    for (int j = i + 1; j < N; j++) {
      if (arr[j] > arr[i]) {
        if (dp[i].first < dp[j].first + 1) {
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
        }
      }
    }
    if (ans.first < dp[i].first) { // 안전하게 뺴기
      ans = {dp[i].first, i};
    }
  }
  cout << ans.first << "\n";
  int idx = ans.second;
  for (int i = 0; i < ans.first; i++) {
    cout << arr[idx] << " ";
    idx = dp[idx].second;
  }
}