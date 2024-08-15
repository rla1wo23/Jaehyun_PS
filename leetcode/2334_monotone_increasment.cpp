#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int validSubarraySize(vector<int> &nums, int threshold) {
  long long N = nums.size();
  stack<pair<int, int>> s; // value, index
  vector<int> dp(N);
  for (int i = 0; i < N; i++) {
  }
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