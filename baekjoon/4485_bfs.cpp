#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  for (int tc = 1; tc < INF; tc++) {
    int N;
    cin >> N;
    if (N == 0)
      return 0;
    int board[130][130];
    int log[130][130];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> board[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        log[i][j] = INF;
      }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    log[0][0] = board[0][0];
    int cnt = 0;
    while (!q.empty()) {
      cnt++;
      pair<int, int> cur = q.front();
      q.pop();
      int point = log[cur.first][cur.second];
      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
          continue;
        if (point + board[nx][ny] > log[nx][ny]) // 갱신 무의미인 경우
          continue;
        q.push({nx, ny});
        log[nx][ny] = point + board[nx][ny];
      }
    }
    cout << "Problem " << tc << ": " << log[N - 1][N - 1] << "\n";
  }
}
