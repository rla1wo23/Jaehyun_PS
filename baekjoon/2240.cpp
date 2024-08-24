#include <algorithm>
#include <iostream>
using namespace std;
int table[2][32][1005];
int time_line[1005];
const int INF = -10005;
int main() {
  int T, W;
  cin >> T >> W;
  for (int i = 1; i <= T; i++) {
    cin >> time_line[i];
  }
  for (int i = 0; i <= W; i++) {
    table[0][i][0] = INF;
    table[1][i][0] = INF;
    table[0][i + 1][0] = INF;
    table[1][i + 1][0] = INF;
  }
  table[0][W][0] = 0;
  int ans = 0;
  for (int t = 1; t <= T; t++) {
    for (int w = 0; w <= W; w++) {
      table[0][w][t] =
          max(table[0][w][t - 1], table[1][w + 1][t - 1]) + (time_line[t] == 1);
      table[1][w][t] =
          max(table[1][w][t - 1], table[0][w + 1][t - 1]) + (time_line[t] == 2);
    }
  }
  for (int i = 0; i <= W; i++) {
    ans = max(table[0][i][T], ans);
    ans = max(table[1][i][T], ans);
  }
  cout << ans;
}