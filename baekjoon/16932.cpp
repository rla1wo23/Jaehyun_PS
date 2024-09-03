#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int board[1005][1005];
int land[1005][1005];
bool vis[1005][1005];
bool is_un[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
int ans = 0;
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
  // 1차 bfs
  vector<int> area;
  area.push_back(0);
  int cnt = 1; // 섬 수
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1 && !vis[i][j]) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        land[i][j] = cnt;
        int a = 1;
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
              continue;
            if (vis[nx][ny] || board[nx][ny] == 0)
              continue;
            q.push({nx, ny});
            a++;
            vis[nx][ny] = true;
            land[nx][ny] = cnt;
          }
        }
        area.push_back(a);
        ans = max(a + 1, ans);
        cnt++;
      }
    }
  }
  // 2차 bfs, 어떤 섬들이 인접해 있나
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) {
        vector<int> cand;
        unordered_map<int, int> used;
        if (i >= 1) {
          cand.push_back(land[i - 1][j]);
          used[land[i - 1][j]] = 1;
        }
        if (j >= 1) {
          if (used[land[i][j - 1]] == 0) {
            cand.push_back(land[i][j - 1]);
            used[land[i][j - 1]] = 1;
          }
        }
        if (i < N - 1) {
          if (used[land[i + 1][j]] == 0) {
            cand.push_back(land[i + 1][j]);
            used[land[i + 1][j]] = 1;
          }
        }
        if (j < M - 1) {
          if (used[land[i][j + 1]] == 0) {
            cand.push_back(land[i][j + 1]);
            used[land[i][j + 1]] = 1;
          }
        }
        used.clear();
        int sum = 1;
        for (int i = 0; i < cand.size(); i++) {
          sum += area[cand[i]];
        }
        ans = max(sum, ans);
      }
    }
  }
  if (area.size() == 1) {
    cout << 1;
    return 0;
  }
  cout << ans;
}