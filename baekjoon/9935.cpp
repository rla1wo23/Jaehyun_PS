#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  string str, sub;
  cin >> str >> sub;
  stack<int> idx;
  stack<char> c;
  idx.push(0);
  for (int i = 0; i < str.size(); i++) {
    c.push(str[i]);
    if (sub[idx.top()] == c.top()) {
      idx.push(idx.top() + 1);
      if (idx.top() == sub.size()) {
        for (int j = 0; j < sub.size(); j++) {
          idx.pop();
          c.pop();
        }
      }
    } else {
      if (sub[0] == c.top()) {
        idx.push(1);
      } else {
        idx.push(0);
      }
    }
  }
  if (c.empty()) {
    cout << "FRULA";
  } else {
    stack<char> output;
    while (!c.empty()) {
      output.push(c.top());
      c.pop();
    }
    while (!output.empty()) {
      cout << output.top();
      output.pop();
    }
  }
}