#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int validSubarraySize(vector<int> &nums, int threshold) {
  long long N = nums.size();
  stack<pair<long long, long long>> s; // value, index
  vector<long long> dp(N);
  s.push({nums[0], 0});
  int idx = 1;
}
int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  validSubarraySize(v, 2000);
}