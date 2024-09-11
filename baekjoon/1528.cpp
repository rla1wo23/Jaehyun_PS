#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N;
int dp[1000005];
int cnt[1000005];
vector<int> cand;
void find_cand(int k) {
  if (k >= N) {
    return;
  }
  dp[k] = 0;
  int nxt = k * 10;
  if (nxt + 4 <= N) {
    cand.push_back(nxt + 4);
    find_cand(nxt + 4);
  }
  if (nxt + 7 <= N) {
    cand.push_back(nxt + 7);
    find_cand(nxt + 7);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  find_cand(0);
  sort(cand.begin(), cand.end());
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == N)
      break;
    for (int i = 0; i < cand.size(); i++) {
      int nxt = cur + cand[i];
      if (nxt > N)
        continue;
      if (cnt[nxt] != 0 && cnt[nxt] <= cnt[cur] + 1)
        continue;
      q.push(cur + cand[i]);
      dp[cur + cand[i]] = cur;
      cnt[cur + cand[i]] = cnt[cur] + 1;
    }
  }
  vector<int> ans;
  if (cnt[N] == 0) {
    cout << -1;
    return 0;
  }
  int idx = N;
  while (idx > 0) {
    ans.push_back(idx - dp[idx]);
    idx = dp[idx];
  }

  sort(ans.begin(), ans.end());
  for (int a : ans) {
    cout << a << " ";
  }
}