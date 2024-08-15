#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int validSubarraySize(vector<int> &nums, int threshold) {
  long long N = nums.size();
  stack<pair<long long, long long>> s; // value, index
  long long i = 0;
  while (i < N) {
    if (s.empty() || s.top().first < nums[i]) {
      s.push({nums[i], i});
      i++;
    } else {
      pair<long long, long long> cur = s.top();
      s.pop();
      long long width;
      if (s.empty()) {
        width = i;
      } else {
        width = i - 1 - s.top().second;
      }
      if (width * cur.first > threshold) {
        return width;
      }
    }
  }
  while (!s.empty()) {
    pair<long long, long long> cur = s.top();
    s.pop();
    long long width;
    if (s.empty()) {
      width = i;
    } else {
      width = i - 1 - s.top().second;
    }
    if (width * cur.first > threshold) {
      return width;
    }
  }
  return -1;
}
int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  cout << validSubarraySize(v, 6);
}