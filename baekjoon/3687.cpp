#include <iostream>
using namespace std;
void print_min(int match) {
  if (match <= 7) {
    switch (match) {
    case 2:
      cout << 1;
      break;
    case 3:
      cout << 7;
      break;
    case 4:
      cout << 4;
      break;
    case 5:
      cout << 2;
      break;
    case 6:
      cout << 6;
      break;
    case 7:
      cout << 8;
      break;
    }
  } else {
    switch (match % 7) {
    case 1:
      cout << 10;
      break;
    case 2:
      cout << 18;
      break;
    case 3:
      if (match == 10) {
        cout << 22;
      } else {
        cout << 200;
        match -= 7;
      }
      break;
    case 4:
      cout << 20;
      break;
    case 5:
      cout << 28;
      break;
    case 6:
      cout << 68;
      break;
    case 0:
      cout << 8;
      break;
    }
    for (int i = 0; i < match / 7 - 1; i++) {
      cout << 8;
    }
  }
}
void print_max(int match) {
  if (match % 2 == 1) {
    cout << 7;
  } else {
    cout << 1;
  }
  for (int i = 0; i < match / 2 - 1; i++) {
    cout << 1;
  }
  cout << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int match;
    cin >> match;
    print_min(match);
    cout << " ";
    print_max(match);
  }
}