#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int target = a[i];
    int st = 0;
    int en = m - 1;
    while (st <= en) {
      int mid = (st + en) / 2;
      if (b[mid] == target) {
        break;
      } else if (b[mid] > target) {
        en = mid - 1;
      } else {
        st = mid + 1;
      }
    }
    if (st > en) {
      ans.push_back(target);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}