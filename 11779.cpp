#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define X first
#define Y second
using namespace std;
int n, m;
int pre[1005];
int table[1005];
const int INF = 0x3f3f3f3f;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    table[i] = INF;
  }
  vector<vector<pair<int, int>>> arr(n + 1); // cost, next
  for (int i = 0; i < m; i++) {
    int u, v, e;
    cin >> u >> v >> e;
    arr[u].push_back({e, v});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  int A, B;
  cin >> A >> B;
  pq.push({0, A});
  table[A] = 0;
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (cur.X != table[cur.Y])
      continue;
    for (int i = 0; i < arr[cur.Y].size(); i++) {
      int nxt = arr[cur.Y][i].Y;
      int cost = cur.X + arr[cur.Y][i].X;
      if (cost < table[nxt]) {
        pq.push({cost, nxt});
        table[nxt] = cost;
        pre[nxt] = cur.Y;
      }
    }
  }
  cout << table[B] << "\n";
  stack<int> s; // 마지막
  s.push(B);
  while (s.top() != A) {
    s.push(pre[s.top()]);
  }
  cout << s.size() << "\n";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}