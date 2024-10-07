#include <iostream>
#include <stack>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int arr[1000005];
  int nums[1000005];
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
    arr[i] = -1;
  }
  stack<pair<int, int>> s;
  int idx = 0;
  while (idx < N) {
    while (!s.empty() && nums[idx] > s.top().first) {
      int mark = s.top().second;
      arr[mark] = nums[idx];
      s.pop();
    }
    s.push({nums[idx], idx});
    idx++;
  }
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
}