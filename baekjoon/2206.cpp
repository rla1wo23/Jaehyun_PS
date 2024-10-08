#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M;
int board[1005][1005];
int count_clean[1005][1005];
bool vis_clean[1005][1005];
int count_broken[1005][1005];
bool vis_broken[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < M; j++) {
      board[i][j] = input[j] - '0';
      count_clean[i][j] = INF;
      count_broken[i][j] = INF;
      vis_clean[i][j] = false;
    }
  }
  queue<pair<int, int>> q;  // 클린큐
  queue<pair<int, int>> bq; // 벽부순큐
  q.push({0, 0});
  count_clean[0][0] = 1;
  vis_clean[0][0] = true;
  while (!q.empty()) {
    int curx = q.front().first;
    int cury = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        continue;
      if (vis_clean[nx][ny])
        continue;
      if (board[nx][ny] == 1) {
        vis_clean[nx][ny] = true;
        bq.push({nx, ny});
        count_broken[nx][ny] = count_clean[curx][cury] + 1;
        continue;
      }
      vis_clean[nx][ny] = true;
      count_clean[nx][ny] = count_clean[curx][cury] + 1;
      q.push({nx, ny});
    }
  }
  while (!bq.empty()) {
    int curx = bq.front().first;
    int cury = bq.front().second;
    bq.pop();
    for (int i = 0; i < 4; i++) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        continue;
      if (board[nx][ny] == 1)
        continue;
      if (count_broken[nx][ny] <= count_broken[curx][cury] + 1)
        continue;
      if (count_clean[nx][ny] <= count_broken[curx][cury] + 1)
        continue;
      count_broken[nx][ny] = count_broken[curx][cury] + 1;
      bq.push({nx, ny});
    }
  }
  int ans = min(count_broken[N - 1][M - 1], count_clean[N - 1][M - 1]);
  if (ans == INF) {
    cout << -1;
  } else {
    cout << ans;
  }
}