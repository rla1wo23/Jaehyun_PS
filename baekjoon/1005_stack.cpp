#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct node {
  int value = 0;
  vector<int> children;
};
node nodes[1005];
int ans_table[1005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int ans = 0;
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
      cin >> nodes[i].value;
      nodes[i].children.clear();
    }
    while (K--) {
      int a, b;
      cin >> a >> b;
      nodes[b].children.push_back(a);
    }
    int w;
    cin >> w;
    stack<pair<int, int>> s; // 번호,누적 cost
    s.push({w, nodes[w].value});
    ans_table[w] = nodes[w].value;
    while (!s.empty()) {
      pair<int, int> cur = s.top();
      s.pop();
      ans = max(ans, cur.second);
      for (int i = 0; i < nodes[cur.first].children.size(); i++) {
        int cn = nodes[cur.first].children[i];
        s.push({cn, cur.second + nodes[cn].value});
      }
    }
    cout << ans << "\n";
    for (int i = 1; i <= N; i++) {
      ans_table[i] = 0;
      nodes[i].children.clear();
    }
  }
}