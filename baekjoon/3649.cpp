#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x;
  while (cin >> x) {
    x = x * 10000000;
    int n;
    cin >> n;
    vector<int> legos(n);
    for (int i = 0; i < n; i++) {
      cin >> legos[i];
    }
    sort(legos.begin(), legos.end());
    int l = 0, r = n - 1;
    bool found = false;
    while (l < r) {
      int sum = legos[l] + legos[r];
      if (sum == x) {
        cout << "yes " << legos[l] << " " << legos[r] << "\n";
        found = true;
        break;
      } else if (sum < x) {
        l++;
      } else {
        r--;
      }
    }
    if (!found) {
      cout << "danger\n";
    }
  }
  return 0;
}
