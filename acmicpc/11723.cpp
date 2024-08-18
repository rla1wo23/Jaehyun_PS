#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_set<int> s;
  int N;
  cin >> N;
  while (N--) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int x;
      cin >> x;
      s.insert(x);
    } else if (cmd == "remove") {
      int x;
      cin >> x;
      if (s.find(x) != s.end()) {
        s.erase(x);
      }
    } else if (cmd == "check") {
      int x;
      cin >> x;
      if (s.find(x) != s.end()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (cmd == "toggle") {
      int x;
      cin >> x;
      if (s.find(x) != s.end()) {
        s.erase(x);
      } else {
        s.insert(x);
      }
    } else if (cmd == "all") {
      for (int i = 1; i <= 20; i++) {
        s.insert(i);
      }
    } else {
      for (int i = 1; i <= 20; i++) {
        s.erase(i);
      }
    }
  }
}