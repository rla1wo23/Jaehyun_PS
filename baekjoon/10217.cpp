#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M, K;
    cin >> N >> M >> K;
    int times[150];
    int costs[150];
    bool done[150];
    vector<vector<pair<int, int>>> cost(N + 1);
    vector<vector<pair<int, int>>> minute(N + 1);
    for (int i = 0; i < K; i++) {
      int u, v, c, d;
      cost[u].push_back({c, v});
      minute[u].push_back({d, v});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 1});
    costs[1] = 0;
    times[1] = 0;
    while (!pq.empty()) {
      int cur = pq.top().second;
      int cur_time = pq.top().first;
      int cur_cost = costs[cur];
      pq.pop();
      for (int i = 0; i < minute[cur].size(); i++) {
        int nxt = minute[cur][i].second;
        int nxt_cost = cost[cur][i].first;
        if (costs[cur] + nxt_cost > M)
          continue;
      }
    }
  }
}