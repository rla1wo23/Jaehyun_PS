#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define speed first.first
#define dir first.second

int R, C, M;
pair<pair<int, int>, int> map[105][105]; //<속력,방향>,크기
int pos = 0;                             // 낚시왕의 현재 위치
int score = 0;                           // 잡은 상어의 크기 합

void hunt() {
  for (int i = 1; i <= R; i++) {
    if (map[i][pos].second != 0) {
      score += map[i][pos].second; // 상어 크기 더하기
      map[i][pos] = {{0, 0}, 0};   // 상어 제거
      break;
    }
  }
}

void sharks_move() {
  pair<pair<int, int>, int> tmp[105][105]; // 임시 맵
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      tmp[i][j] = {{0, 0}, 0}; // 임시 맵 초기화
    }
  }

  // 상어 이동
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (map[i][j].second == 0)
        continue; // 상어가 없으면 건너뜀

      int s = map[i][j].speed;  // 속력
      int d = map[i][j].dir;    // 방향
      int z = map[i][j].second; // 크기
      int x = i, y = j;

      // 수직 이동 (위: 1, 아래: 2)
      if (d == 1 || d == 2) {
        int mod = (R - 1) * 2; // 경계를 고려한 반복 패턴
        s = s % mod;           // 속력을 주기적으로
        for (int k = 0; k < s; ++k) {
          if (x == 1)
            d = 2; // 위쪽 끝에 도달하면 아래로
          else if (x == R)
            d = 1; // 아래쪽 끝에 도달하면 위로
          x += (d == 1) ? -1 : 1;
        }
      }
      // 수평 이동 (오른쪽: 3, 왼쪽: 4)
      else {
        int mod = (C - 1) * 2;
        s = s % mod;
        for (int k = 0; k < s; ++k) {
          if (y == 1)
            d = 3; // 왼쪽 끝에 도달하면 오른쪽으로
          else if (y == C)
            d = 4; // 오른쪽 끝에 도달하면 왼쪽으로
          y += (d == 3) ? 1 : -1;
        }
      }

      if (tmp[x][y].second < z) {
        tmp[x][y] = {{s, d}, z};
      }
    }
  }

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      map[i][j] = tmp[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C >> M;

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      map[i][j] = {{0, 0}, 0};
    }
  }

  for (int i = 0; i < M; i++) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    map[r][c] = {{s, d}, z};
  }

  while (pos < C) {
    pos++;
    hunt();
    sharks_move();
  }

  cout << score;

  return 0;
}
