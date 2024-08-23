#include <algorithm>
#include <iostream>
using namespace std;
char board[10][10];
int N, M;
pair<int, int> pos[2]; // 0빨강, 1파랑
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 하,우,상,좌
int ans = 100;

// 0무난 멈춤, 1goal(성공), 2(실패)
int move(int dir, int kind) {
  int x = pos[kind].first;
  int y = pos[kind].second;
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  while (board[nx][ny] == '.') {
    nx += dx[dir];
    ny += dy[dir];
  }
  if (board[nx][ny] == 'O') {
    // 구슬이 구멍에 빠지면, 보드에서 구슬을 제거
    board[x][y] = '.';
    return kind == 0 ? 1 : 2;
  }
  nx -= dx[dir];
  ny -= dy[dir];
  board[x][y] = '.';
  if (kind == 0) {
    board[nx][ny] = 'R';
    pos[0] = {nx, ny};
  } else {
    board[nx][ny] = 'B';
    pos[1] = {nx, ny};
  }
  return 0;
}

int moveBoth(int dir) {
  int redRes = 0, blueRes = 0;
  if (dir == 0) { // Down
    if (pos[0].first > pos[1].first) {
      redRes = move(dir, 0);
      blueRes = move(dir, 1);
    } else {
      blueRes = move(dir, 1);
      redRes = move(dir, 0);
    }
  } else if (dir == 1) { // Right
    if (pos[0].second > pos[1].second) {
      redRes = move(dir, 0);
      blueRes = move(dir, 1);
    } else {
      blueRes = move(dir, 1);
      redRes = move(dir, 0);
    }
  } else if (dir == 2) { // Up
    if (pos[0].first < pos[1].first) {
      redRes = move(dir, 0);
      blueRes = move(dir, 1);
    } else {
      blueRes = move(dir, 1);
      redRes = move(dir, 0);
    }
  } else if (dir == 3) { // Left
    if (pos[0].second < pos[1].second) {
      redRes = move(dir, 0);
      blueRes = move(dir, 1);
    } else {
      blueRes = move(dir, 1);
      redRes = move(dir, 0);
    }
  }

  // 동시에 떨어지는 경우 처리
  if (redRes == 1 && blueRes == 2) {
    return 2; // 실패로 간주
  }
  if (redRes == 1 && blueRes == 0)
    return 1; // 빨간 구슬만 들어가면 성공
  if (blueRes == 2)
    return 2; // 파란 구슬이 들어가면 실패

  return 0; // 아무도 안 들어가면 계속 진행
}
// 롤백은 여기서 구현한다

void back_tracking(int k) {
  if (k == 10)
    return;

  char tmp[10][10];
  pair<int, int> tmp_pos[2];

  for (int t = 0; t < 4; t++) {
    // 현재 상태 저장
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        tmp[i][j] = board[i][j];
      }
    }
    tmp_pos[0] = pos[0];
    tmp_pos[1] = pos[1];

    int res = moveBoth(t);
    if (res == 1) {
      ans = min(ans, k + 1);
      return;
    } else if (res != 2) { // 실패하지 않은 경우에만 백트래킹
      back_tracking(k + 1);
    }

    // 이전 상태로 복구
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        board[i][j] = tmp[i][j];
      }
    }
    pos[0] = tmp_pos[0];
    pos[1] = tmp_pos[1];
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        pos[0] = {i, j};
      } else if (board[i][j] == 'B') {
        pos[1] = {i, j};
      }
    }
  }
  back_tracking(0);
  if (ans == 100) {
    cout << -1;
  } else {
    cout << ans;
  }
}