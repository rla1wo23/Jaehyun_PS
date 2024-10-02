#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  set<int> bset;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;
    bset.insert(num);
  }
  sort(v.begin(), v.end());
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (bset.find(v[i]) == bset.end()) {
      ans.push_back(v[i]);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}