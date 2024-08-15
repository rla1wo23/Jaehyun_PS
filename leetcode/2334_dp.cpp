#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int validSubarraySize(vector<int> &nums, int threshold) {
  int N = nums.size();
  vector<int> skip(N);
  int maxNum = 0;
  for (int i = 0; i < N; i++) {
    maxNum = max(maxNum, nums[i]);
  }
  unordered_map<int, int> um;
  int ts = threshold;
  for (int t = 1; ts >= 1; t++) {
    while ((threshold / (t * 2)) > maxNum) {
      t = t * 2;
    };
    int straight = 0;
    ts = threshold / t;
    if (um[ts] == 1) {
      continue;
    }
    um[ts] = 1;
    for (int i = 0; i < N; i++) {
      if (skip[i] != 0) {
        straight += skip[i];
        i += skip[i] - 1;
        if (straight >= t) {
          return t;
        }
        continue;
      }
      if (nums[i] >= ts + 1) {
        straight++;
      } else {
        skip[i - straight] = straight;
        straight = 0;
      }
      if (straight >= t) {
        return t;
      }
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
  validSubarraySize(v, 360);
}