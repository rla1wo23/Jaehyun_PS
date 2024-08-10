#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  string str;
  cin >> N >> str;
  int r_s = 0, b_s = 0, r_e = 0, b_e = 0;
  int rc = 0, bc = 0;

  if (str[0] == 'R') {
    rc++;
  } else {
    bc++;
  }

  int i = 1;
  for (; i < N && str[i] == str[i - 1]; i++) {
    if (str[i] == 'R') {
      r_s++;
      rc++;
    } else {
      b_s++;
      bc++;
    }
  }

  int j = str.length() - 1;
  if (str[j] == 'R') {
    rc++;
    r_e++;
  } else {
    bc++;
    b_e++;
  }
  j--;

  for (; j >= 0 && str[j] == str[j + 1]; j--) {
    if (str[j] == 'R') {
      r_e++;
      rc++;
    } else {
      b_e++;
      bc++;
    }
  }

  for (; i <= j && i < N; i++) {
    if (str[i] == 'R') {
      rc++;
    } else {
      bc++;
    }
  }

  int ans = min(rc - r_e, bc - b_s);
  ans = min(ans, bc - b_e);
  ans = min(ans, rc - r_s);

  cout << ans << endl;

  return 0;
}
