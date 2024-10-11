#include <iostream>
#include <stack>
using namespace std;
int arr[500005];
int ans[500005];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  stack<int> s;
  for (int i = 0; i < N; i++) {
    while (!s.empty() && arr[s.top()] <= arr[i]) {
      ans[s.top()]++;
      s.pop();
    }
    if (!s.empty()) {
      ans[s.top()]++;
    }
    s.push(i);
  }
  for (int i = 0; i < N; i++) {
    cout << i << ":" << ans[i] << " ";
  }
}
