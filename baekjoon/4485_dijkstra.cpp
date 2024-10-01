#include <iostream>
#include <queue>
using namespace std;
int INF = 0x3f3f3f3f;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  for (int tc = 1; tc < INF; tc++) {
    int N;
    cin >> N;
    if (N == 0)
      return 0;
    int board[130][130];
    int logs[130][130];
    bool done[130][130];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> board[i][j];
        logs[i][j] = INF;
        done[i][j] = false;
      }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    logs[0][0] = board[0][0];
    done[0][0] = true;
    pq.push({board[0][0], {0, 0}});
    while (!pq.empty()) {
      int cur_p = pq.top().first;
      int cur_x = pq.top().second.first;
      int cur_y = pq.top().second.second;
      if (logs[cur_x][cur_y] != cur_p)
        continue;
      pq.pop();
      for (int i = 0; i < 4; i++) {
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
          continue;
        if (done[nx][ny])
          continue;
        pq.push({cur_p + board[nx][ny], {nx, ny}});
        logs[nx][ny] = cur_p + board[nx][ny];
        done[nx][ny] = true;
      }
    }
    cout << "Problem " << tc << ": " << logs[N - 1][N - 1] << "\n";
  }
}