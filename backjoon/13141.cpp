#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int board[205][205] = {0};
int edges[205][205] = {0};
int cMost = 0;
vector<vector<int>> adjs(205);
vector<int> cycles;
const int INF = 200000;
double ans = 200000.0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  cout.precision(1);
  cout << fixed;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      board[i][j] = INF;
    }
  }
  cycles.resize(N + 1, 0);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b;
    cin >> c;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
    edges[a][b] = max(edges[a][b], c);
    edges[b][a] = max(edges[b][a], c);
    if (a == b) {
      cMost = max(cMost, c);
      cycles[a] = max(cycles[a], c);
    }
    if (board[a][b] > c) {
      board[a][b] = c;
      board[b][a] = c;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) {
        board[i][j] = 0; // 여기 개혁해야함.
        continue;
      }
      if (board[i][j] == 0) {
        board[i][j] = INF;
      }
    }
  }
  for (int k = 1; k <= N; k++) {
    for (int s = 1; s <= N; s++) {
      for (int t = 1; t <= N; t++) {
        if (board[s][t] > board[s][k] + board[k][t]) {
          board[s][t] = board[s][k] + board[k][t];
        }
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    int cand = 0; // i에서 시작할 시 최대 거리 저장
    int tmpIdx = 0;
    double cMax = 0;
    for (int j = 1; j <= N; j++) {
      if (board[i][j] > cand) {
        cand = board[i][j];
        tmpIdx = j;
      }
      cMax = max(cMax, cycles[j] / 2.0 + board[i][j] * 1.0);
      // 싸이클 또한 정답의 후보임
    }
    if (tmpIdx < 1 || tmpIdx > N)
      continue;
    int lastDistance = 0; // 마지막 정점으로 이르는
    for (int d = 0; d < adjs[tmpIdx].size(); d++) {
      int k = adjs[tmpIdx][d];
      lastDistance = max(board[i][k] + edges[k][tmpIdx], lastDistance);
    }
    double test = max((lastDistance - cand) / 2.0 + cand, cMax);
    if (lastDistance > cand) {
      ans = min(test, ans);
    } else {
      ans = min(cand * 1.0, ans);
    }
  }
  cout << max(ans, cMost / 2.0);
}