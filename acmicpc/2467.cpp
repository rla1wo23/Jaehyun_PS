#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int st = 0;
  int en = N - 1;
  int ans = abs(v[0] + v[N - 1]);
  int ans_s = 0;
  int ans_e = N - 1;
  while (st < en) {
    int mid = v[st] + v[en];
    if (mid == 0) {
      cout << v[st] << " " << v[en];
      return 0;
    }
    if (abs(v[st] + v[en]) < ans) {
      ans_s = st;
      ans_e = en;
      ans = abs(v[st] + v[en]);
    }
    if (mid > 0) { // 너무 커?
      en--;
    } else {
      st++; // 너무 작아?
    }
  }
  cout << v[ans_s] << " " << v[ans_e];
  return 0;
}