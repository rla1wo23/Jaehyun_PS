#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[105][105];
int island[105][105];
bool vis[105][105];
int around(int x, int y) {
  if (x > 0 && board[x - 1][y]) {
    return island[x - 1][y];
  }
  if (y > 0 && board[x][y - 1]) {
    return island[x][y - 1];
  }
  if (x < N - 1 && board[x + 1][y]) {
    return island[x + 1][y];
  }
  if (y < N - 1 && board[x][y + 1]) {
    return island[x][y + 1];
  }
  return 0;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  int islands = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] && !vis[i][j]) {
        island[i][j] = islands;
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
              continue;
            if (vis[nx][ny] || board[nx][ny] == 0)
              continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
            island[nx][ny] = islands;
          }
        }
        islands++;
      }
    }
  }
  int ans = 99999;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0) {
        int st = around(i, j);
        if (st == 0)
          continue;
        for (int i = 0; i < N; i++) {
          fill(vis[i], vis[i] + N, false);
        }
        queue<pair<pair<int, int>, int>> q;
        q.push({{i, j}, 1});
        vis[i][j] = true;
        while (!q.empty()) {
          int x = q.front().first.first;
          int y = q.front().first.second;
          int len = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
              continue;
            if (vis[nx][ny])
              continue;
            vis[nx][ny] = true;
            if (island[nx][ny] && island[nx][ny] != st) {
              ans = min(ans, len);
              while (!q.empty())
                q.pop(); // 현재 BFS 탐색을 종료
              break;
            }
            if (island[nx][ny])
              continue;
            q.push({{nx, ny}, len + 1});
          }
        }
      }
    }
  }
  cout << ans << "\n";
}
