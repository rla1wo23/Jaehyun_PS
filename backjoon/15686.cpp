#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// 1: naive approach전부 비교해도, 시간 안에 들어올 것 같다.
// 각 치킨집에서, 모든 집까지의 거리를 각각 벡터에 저장
// min으로 비교 -> 배제할지, 남겨둘 지를 선택해서 고르면 백트래킹 가능!
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> costs; // 각 치킨집에서, 가정집까지 코스트 계산
int arr[13]; // 백트래킹에 쓰일 배열에, 몇번째 치킨집이 들어가있는지를 저장
bool used[13]; //
bool clear[13];

int N, M;
int H, C; // 가정집 수, 치킨집 수
int board[50][50];
int ans = 0x7fffffff;
void back_tracking(int k) { // 살려둘 애를 구하기
  if (k == M) {
    int minC = 0;
    for (int i = 0; i < H; i++) { // 사용할 치킨집에서, 가장 적은 거리 더하기
      int tmp = 0x7fffffff;
      for (int j = 0; j < k; j++) {
        tmp = min(costs[arr[j]][i], tmp);
      }
      minC += tmp;
    }
    ans = min(ans, minC);
  } else {
    for (int i = 0; i < C; i++) {
      if (used[k] == true || clear[i] == true)
        continue;
      arr[k] = i;
      used[k] = true;
      back_tracking(k + 1);
      used[k] = false;
      if (k == 0) {
        clear[k] = true;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  costs.resize(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        H++;
        house.push_back({i, j});
      }
      if (board[i][j] == 2) {
        C++;
        chicken.push_back({i, j});
      }
    }
  }
  costs.resize(C);
  for (int i = 0; i < C; i++) {
    pair<int, int> cur = chicken[i];
    for (int j = 0; j < H; j++) {
      int cost = abs(cur.first - house[j].first);
      cost += abs(cur.second - house[j].second);
      costs[i].push_back(cost);
    }
  }
  back_tracking(0);
  cout << ans;
}