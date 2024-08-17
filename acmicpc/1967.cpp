#include <algorithm>
#include <iostream>
#include <vector>
int N, ans = 0;
using namespace std;
int depth[10001];
struct node {
  vector<int> childs;
  vector<int> edges; // 간선의 가중치
};
node nodes[10001];
int find_depth(int k) {
  vector<int> d;
  for (int i = 0; i < nodes[k].childs.size(); i++) {
    d.push_back(find_depth(nodes[k].childs[i]) + nodes[k].edges[i]);
  }
  if (d.size() == 0) {
    return 0;
  }
  if (d.size() == 1) {
    ans = max(d[0], ans);
    return d[0];
  } else {
    sort(d.begin(), d.end());
    ans = max(ans, d[d.size() - 1] + d[d.size() - 2]);
    return d[d.size() - 1];
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int p, c, e;
    cin >> p >> c >> e;
    nodes[p].childs.push_back(c);
    nodes[p].edges.push_back(e);
  }
  find_depth(1);
  cout << ans;
}