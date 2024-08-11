#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[200001];
int N, target;
bool vis[200001];

int main() {
  cin >> N >> target;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, N}); // 첫 번째 값은 시간, 두 번째 값은 위치
  vis[N] = true;
  map[N] = 0;

  while (!pq.empty()) {
    int cur_time = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (cur == target) {
      cout << cur_time;
      return 0;
    }

    if (cur * 2 <= 200000 && !vis[cur * 2]) {
      vis[cur * 2] = true;
      pq.push({cur_time, cur * 2}); // 순간이동은 시간 증가 없음
    }

    if (cur + 1 <= 200000 && !vis[cur + 1]) {
      vis[cur + 1] = true;
      pq.push({cur_time + 1, cur + 1});
    }

    if (cur - 1 >= 0 && !vis[cur - 1]) {
      vis[cur - 1] = true;
      pq.push({cur_time + 1, cur - 1}); // 걷는 경우 1초 추가
    }
  }

  return 0;
}
