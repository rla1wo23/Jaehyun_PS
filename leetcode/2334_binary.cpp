#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int validSubarraySize(vector<int> &nums, int threshold) {
  int N = nums.size();
  int ts = threshold;
  for (int t = 2; ts >= 1; t++) {
    int straight = 0;
    for (int i = 0; i < N; i++) {
      if (nums[i] > ts) {
        straight++;

      } else {
        straight = 0;
      }
      if (straight >= t - 1) {
        return t - 1;
      }
    }
    ts = threshold / t;
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
  validSubarraySize(v, 6);
}