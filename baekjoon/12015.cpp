#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> num(N);
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }
  vector<int> dp;
  dp.push_back(num[0]);
  for (int i = 1; i < N; i++) {
    if (dp[dp.size() - 1] < num[i]) {
      dp.push_back(num[i]);
    } else {
      int idx = lower_bound(dp.begin(), dp.end(), num[i]) - dp.begin();
      dp[idx] = num[i];
    }
  }
  cout << dp.size();
}