#include <algorithm>
#include <iostream>
#include <vector>
int N, M;
int board[205][205];
const int INF = 0x3f3f3f3f;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      board[i][j] = INF;
      if (i == j) {
        board[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    board[a][b] = c;
  }
  int K;
  cin >> K;
  vector<int> cities(K);
  for (int i = 0; i < K; i++) {
    cin >> cities[i];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
      }
    }
  }
  vector<int> ans;
  int ansNum = INF;
  for (int i = 1; i <= N; i++) {
    int minMax = 0;
    for (int c = 0; c < K; c++) {
      minMax = max(minMax, board[i][cities[c]] + board[cities[c]][i]);
    }
    if (minMax <= ansNum) {
      if (minMax == ansNum) {
        ans.push_back(i);
      } else {
        ansNum = minMax;
        ans.clear();
        ans.push_back(i);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
