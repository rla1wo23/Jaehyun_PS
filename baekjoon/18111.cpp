#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int map[501][501];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, B;
  cin >> N >> M >> B;
  int low = 257;
  int high = 0;
  int heights[257] = {0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int k;
      cin >> k;
      heights[k]++;
      low = min(k, low);
      high = max(k, high);
    }
  }
  vector<pair<int, int>> v;
  for (int i = low; i <= high; i++) { // 이거 누적합으로 바꾸면 더 빠름
    if (heights[i] != 0)
      v.push_back({i, heights[i]});
  }
  int ans = 0x7f7f7f7f;
  int ans_height = 0;
  for (int h = low; h <= high; h++) {
    int cost = 0;
    int blocks = B;
    for (int i = 0; i < v.size(); i++) { // 점점
      if (h == v[i].first)
        continue;
      if (h < v[i].first) { // 내 목표 높이보다 높은 경우, 파야함
        cost += 2 * v[i].second * (v[i].first - h);
        blocks += v[i].second * (v[i].first - h);
      } else if (h > v[i].first) { // 목표 높이보다 낮은 경우, 메워야 함
        cost += (h - v[i].first) * v[i].second;
        blocks -= (h - v[i].first) * v[i].second;
      }
    }
    if (cost <= ans && blocks >= 0) {
      ans = cost;
      ans_height = h;
    }
  }
  cout << ans << " " << ans_height;
}