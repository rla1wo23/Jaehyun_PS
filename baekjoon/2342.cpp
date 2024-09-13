#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int input[100005];
int the_other[2][100005]; // 반대발의 위치
int dp[2][100005];        // 0: 왼발이 거기에 있다.
int len;

int cost(int a, int b) {
  if (a == b)
    return 1; // 같은 지점을 다시 누를 때
  if (a == 0 || b == 0)
    return 2; // 중점(0)에서 다른 지점으로 이동
  int dif = abs(a - b);
  if (dif == 2)
    return 4; // 반대편으로 이동
  if (dif == 1)
    return 3; // 인접한 지점으로 이동
  return 1; // 기타 경우(예를 들어 잘못된 입력에 대비해 기본값 설정)
}

int jump(int idx) {
  int cnt = 0;
  while (idx + cnt <= len && input[idx] == input[idx + cnt + 1]) {
    cnt++;
  }
  return cnt;
}

void solve() {
  for (int i = 1; i <= len; i++) {
    int before = i - 1;
    int j = jump(i); // 연속된 같은 숫자의 개수를 가져옴

    // 전에 왼쪽 발로 눌렀고, 이번에도 왼쪽 발로 누르는 케이스
    dp[0][i + j] = dp[0][before] + cost(input[before], input[i]) + j;
    the_other[0][i + j] = the_other[0][before];

    // 전에는 오른발로 눌렀지만, 이번에는 왼쪽 발로 누르는 케이스
    if (the_other[0][before] != input[i]) {
      int cand = dp[1][before] + cost(the_other[1][before], input[i]) + j;
      if (dp[0][i + j] > cand) {
        dp[0][i + j] = cand;
        the_other[0][i + j] = input[before];
      }
    }

    // 전에 오른발로 눌렀고, 이번에도 오른발로 누르는 케이스
    dp[1][i + j] = dp[0][before] + cost(input[before], input[i]) + j;
    the_other[1][i + j] = the_other[1][before];

    // 전에는 왼발로 눌렀지만, 이번에는 오른발로 누르는 케이스
    if (the_other[1][before] != input[i]) {
      int cand = dp[0][before] + cost(the_other[0][before], input[i]) + j;
      if (dp[1][i + j] > cand) {
        dp[1][i + j] = cand;
        the_other[1][i + j] = input[before];
      }
    }
    i += j;
  }
}

int main() {
  input[0] = 0;
  dp[0][0] = 0;
  dp[1][0] = 0;
  the_other[0][0] = 0;
  the_other[1][0] = 0;

  int in = 1;
  int idx = 1;
  cin >> in;
  while (in != 0) {
    input[idx] = in;
    idx++;
    cin >> in;
  }
  len = idx - 1;

  solve();

  cout << min(dp[0][len], dp[1][len]) << endl; // 최소 비용만 출력
}
