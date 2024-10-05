#include <iostream>
using namespace std;
int nums[10];
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    nums[str[i] - '0']++;
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9)
      continue;
    ans = max(ans, nums[i]);
  }
  ans = max((nums[6] + nums[9] + 1) / 2, ans);
  cout << ans;
}