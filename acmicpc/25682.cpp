#include <algorithm>
#include <iostream>
using namespace std;
int N, M, K;
pair<int, int> sum[2005][2005]; // 짝수 pair수, first가 짝수 검정
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    sum[0][i] = {0, 0};
    sum[i][0] = {0, 0};
    int oddB = 0;
    int evenB = 0;
    for (int j = 1; j <= M; j++) {
      char c;
      cin >> c;
      if (c == 'B') {
        if (j % 2 == 0) {
          evenB++;
        } else {
          oddB++;
        }
      }
      sum[i][j] = {evenB, oddB};
    }
  }
  int ans = 0x7fffffff;
  for (int i = 1; i <= N - K + 1; i++) {
    for (int j = 1; j <= M - K + 1; j++) {
      int tmp = 0;
      // i가 짝수, 행도 짝수일 때 때 이렇게 계산하면 되긴 함
      for (int a = 0; a < K; a++) {
        if (a % 2 == 0) {
          tmp += (K + 1) / 2 -
                 (sum[i + a][j + K - 1].first - sum[i + a][j - 1].first);
          tmp += sum[i + a][j + K - 1].second - sum[i + a][j - 1].second;
        } else {
          tmp += sum[i + a][j + K - 1].first - sum[i + a][j - 1].first;
          tmp +=
              K / 2 - sum[i + a][j + K - 1].second + sum[i + a][j - 1].second;
        }
      }
      if (tmp < 0)
        tmp = ans;
      ans = min(ans, tmp);
      tmp = 0;
      for (int a = 0; a < j + K; a++) {
        if (a % 2 == 0) {
          tmp += (K + 1) / 2 -
                 (sum[i + a][j + K - 1].second - sum[i + a][j - 1].second);
          tmp += sum[i + a][j + K - 1].first - sum[i + a][j - 1].first;
        } else {
          tmp += sum[i + a][j + K - 1].second - sum[i + a][j - 1].second;
          tmp += K / 2 - sum[i + a][j + K - 1].first + sum[i + a][j - 1].first;
        }
      }
      if (tmp < 0)
        tmp = ans;
      ans = min(ans, tmp);
    }
  }
  cout << ans;
}

// 제자리를 결정 하려면 어떻게 해야하지? 변수를 2개만들까? 홀수검은색 개수랑
// 짝수 검은색 개수를 셀까 제자리에 있는 애가 몇 개인지를 카운팅해야함.
// 그리고 검은색 시작이 제자리인 경우랑, 흰색 시작이 제자리인 경우 두 가지를
// 쪼개야 한다.
// 만약 검은색 시작이다->짝수 행(0,2,4...)에는 (K+1)/2 개의 홀수검정이 있어야
// 하고, 홀수 행에는 (K/2)개의 짝수 검정이 있어야 함

// 짝수 열의 수는, (K+1)/2개, 홀수 열의 수는 K/2개이다.
//  검정시작 case:
//  짝수행, 짝수열(목표: 검정색) 칠하는 횟수: (K+1)/2-SUM(EvenB)
//  짝수행, 홀수열(목표: 흰색) 칠하는 횟수: SUM(oddB)
//  홀수행, 짝수열(목표:흰색), 칠하는 횟수: SUM(EvenB)
//  홀수행, 홀수열(목표:검정색) K/2의 oddK만큼의 (K/2)-SUM(oddB)

// 흰색 시작 case:
// 짝수행,짝수 열(목표:흰색)  칠하는 횟수: SUM(EvenB)
// 짝수행,홀수 열(목표:검정색) 칠하는 횟수: (K/2)-oddBlack
// 홀수행, 짝수 열(목표:검정색) 칠수: (K+1)/2-EvenBlack
// 홀수행, 홀수 열(목표:흰색 칠수:SUM(oddB)
// SUM은 어떻게 구하노? (x+K-1) - (x-1)
