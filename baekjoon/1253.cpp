#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// 나를 배제한 두 수의 합으로, 나를 표현할 수 있는가?
// 1:N^2에 합을 구하고, 그 결과를 합 um에 저장한다.
// 2:단, 0과 합쳐지는 수는, 나 말고 나와 같은 수가 더 있는 경우에만 저장한다.
// 3:다시 N번씩 돌면서 확인한다.
vector<int> v;
unordered_map<int, int> sum;
unordered_map<int, int> cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    v.push_back(k);
    cnt[k]++;
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (v[i] == 0 && v[j] == 0) {
        if (cnt[0] > 2) {
          sum[0] = 1;
        }
      } else if (v[i] == 0) {
        if (cnt[v[j]] > 1) {
          sum[v[j]] = 1;
        }
      } else if (v[j] == 0) {
        if (cnt[v[i]] > 1) {
          sum[v[i]] = 1;
        }
      } else {
        sum[v[i] + v[j]] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (sum[v[i]] == 1) {
      ans++;
    }
  }
  cout << ans;
}