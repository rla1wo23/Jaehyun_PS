#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int arr[100001] = {0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  string str = "";
  stack<int> s;
  int cnt = 1;
  for (int i = 0; i <= cnt; i++) {
    int k;
    cin >> k;
    if (arr[k]) {
      if (s.top() == k) {
        str += "-\n";
        s.pop();
      } else {
        str = "NO";
        break;
      }
    } else {
      while (cnt < k) {
        cnt++;
        str += "+\n";
        s.push(cnt);
        arr[cnt] = 1;
      }
    }
  }
  cout << str;
}