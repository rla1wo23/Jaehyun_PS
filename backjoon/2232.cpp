#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
struct node {
  int parents_num = 0;
  vector<int> cihlds;
};
node nodes[32005];
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    nodes[a].cihlds.push_back(b);
    nodes[b].parents_num++;
  }
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (nodes[i].parents_num == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (nodes[cur].parents_num != 0) {
      q.push(cur);
      continue;
    }
    cout << cur << " ";
    for (int i = 0; i < nodes[cur].cihlds.size(); i++) {
      nodes[nodes[cur].cihlds[i]].parents_num--;
      if (nodes[nodes[cur].cihlds[i]].parents_num == 0) {
        q.push(nodes[cur].cihlds[i]);
      }
    }
  }
}