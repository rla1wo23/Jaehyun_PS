#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_map<string, int> um;
  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    string str;
    cin >> str;
    int ssize = str.size();
    bool check = false;
    for (int i = 0; i < ssize; i++) {
      string cand = "";
      for (int j = 0; j < ssize; j++) {
        cand += str[(i + j) % ssize];
      }
      if (um[cand] == 1) {
        check = true;
        break;
      }
    }
    if (!check) {
      cnt++;
      um[str] = 1;
    }
  }
  cout << cnt;
}