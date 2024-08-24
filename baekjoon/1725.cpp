#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int histogram(vector<int> &nums) {
  long long N = nums.size();
  stack<pair<long long, long long>> s; // value, index
  long long ans = 0;
  long long i = 0;

  while (i < N) {
    if (s.empty() || s.top().first <= nums[i]) {
      s.push({nums[i], i});
      i++;
    } else {
      pair<long long, long long> cur = s.top();
      s.pop();
      long long width = s.empty() ? i : (i - s.top().second - 1);
      ans = max(ans, cur.first * width);
    }
  }
  while (!s.empty()) {
    pair<long long, long long> cur = s.top();
    s.pop();
    long long width = s.empty() ? i : (i - s.top().second - 1);
    ans = max(ans, cur.first * width);
  }

  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  cout << histogram(v);
}
