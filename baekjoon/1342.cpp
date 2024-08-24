#include <iostream>
#include <vector>
using namespace std;
vector<int> digit;
int N;
int is_used[26] = {0};
int arr[10];
int ans = 0;
void back_tracking(int k) {
  if (k == N) {
    ans++;
  } else {
    for (int i = 0; i < digit.size(); i++) {
      int nxt = digit[i];
      if (is_used[nxt] == 0) {
        continue;
      }
      if (k >= 1) {
        if (arr[k - 1] == nxt)
          continue;
      }
      is_used[digit[i]]--;
      arr[k] = digit[i];
      back_tracking(k + 1);
      is_used[digit[i]]++;
    }
  }
}
int main() {
  string str;
  cin >> str;
  N = str.size();
  for (int i = 0; i < str.size(); i++) {
    if (is_used[str[i] - 'a'] == 0)
      digit.push_back(str[i] - 'a');
    is_used[str[i] - 'a']++;
  }
  if (digit.size() == str.size()) {
    int sum = 1;
    for (int i = 2; i <= str.size(); i++) {
      sum *= i;
    }
    cout << sum;
  } else {
    back_tracking(0);
    cout << ans;
  }
}