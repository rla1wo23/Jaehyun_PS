#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int board[20][20];
pair<int, int> shark_pos;
int shark_size = 2;
int eating_cnt = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.second == b.second) {
    if (a.first.first == b.first.first) {
      return a.first.second < b.first.second;
    } else {
      return a.first.first < b.first.first;
    }
  } else {
    return a.second < b.second;
  }
}
void eat(int x, int y) {
  eating_cnt++;
  if (eating_cnt == shark_size) {
    eating_cnt = 0;
    shark_size++;
  }
  board[x][y] = 0;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        shark_pos = {i, j};
        board[i][j] = 0;
      }
    }
  }
  int spx = shark_pos.first;
  int spy = shark_pos.second;
  int ans = 0;
  while (true) {
    queue<pair<pair<int, int>, int>> q; // 좌표,이동횟수
    q.push({{spx, spy}, 0});
    bool find = false;
    bool vis[20][20];
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        vis[i][j] = false;
      }
    }
    vector<pair<pair<int, int>, int>> fc;
    while (!q.empty()) {
      int curx = q.front().first.first;
      int cury = q.front().first.second;
      int curcnt = q.front().second;
      vis[curx][cury] = true;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        int ncnt = curcnt + 1;
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) // 범위 벗어나면 컷
          continue;
        if (vis[nx][ny]) // 이미 방문해도 컷
          continue;
        if (board[nx][ny] > shark_size) // 크면 못지나감
          continue;
        vis[nx][ny] = true;

        if (board[nx][ny] > 0 && board[nx][ny] < shark_size) {
          fc.push_back({{nx, ny}, ncnt});
          continue;
        }
        q.push({{nx, ny}, ncnt});
      }
    }
    if (fc.empty()) {
      break;
    } else {
      sort(fc.begin(), fc.end(), cmp);
      spx = fc[0].first.first;
      spy = fc[0].first.second;
      ans += fc[0].second;
      eat(spx, spy);
    }
  }
  cout << ans << "\n";
}