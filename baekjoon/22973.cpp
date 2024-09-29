#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
  long long K;
  cin >> K;
  if (K == 0) {
    cout << 0;
    return 0;
  }
  if (K % 2 == 0) {
    cout << -1;
    return 0;
  }
  queue<pair<long long, int>> q;
  q.push({0, 0});

  unordered_map<long long, bool> visited;
  visited[0] = true;

  while (!q.empty()) {
    long long cur = q.front().first;
    int jumps = q.front().second;
    q.pop();

    if (cur == K) {
      cout << jumps;
      return 0;
    }
    long long next_jump = (1LL << jumps);
    long long nxt_r = cur + next_jump;
    long long nxt_l = cur - next_jump;

    if (!visited[nxt_r] && abs(nxt_r) <= 1e12) {
      visited[nxt_r] = true;
      q.push({nxt_r, jumps + 1});
    }

    if (!visited[nxt_l] && abs(nxt_l) <= 1e12) {
      visited[nxt_l] = true;
      q.push({nxt_l, jumps + 1});
    }
  }

  cout << -1;
  return 0;
}
