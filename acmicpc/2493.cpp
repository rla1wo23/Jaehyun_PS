#include <iostream>
#include <stack>
using namespace std;
int ans[500005] = {0};
int main() {
  stack<pair<int, int>> s;
  int N;
  cin >> N;
  s.push({0, 0});
  for (int i = 1; i <= N; i++) {
    int k;
    cin >> k;
    pair<int, int> cur;
    while (!s.empty()) {
      cur = s.top();
      if (cur.first < k) {
        s.pop();
      } else {
        break;
      }
    }
    if (s.empty()) {
      ans[i] = 0;
    } else {
      ans[i] = cur.second;
    }
    s.push({k, i});
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
}