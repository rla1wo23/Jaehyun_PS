#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  while (N--) {
    string str;
    cin >> str;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'O') {
        cnt++;
        ans += cnt;
      } else {
        cnt = 0;
      }
    }
    cout << ans << "\n";
  }
}