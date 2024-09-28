#include <iostream>
using namespace std;
int N, P, T;
int arr[2005];
int main() {
  cin >> N;
  cin >> P >> T;
  int start_pos = 0;
  int cnt = 1;
  bool up = true;
  for (int i = 0; i < T; i++) {
    if (up) {
      start_pos = (start_pos + cnt) % (2 * N);
      cnt++;
      if (cnt == 2 * N) {
        up = false;
      }
    } else {
      if (start_pos < cnt) {
        start_pos = 2 * N - (cnt - start_pos);
      } else {
        start_pos = start_pos - cnt;
      }
      cnt--;
      if (cnt == 0) {
        up = true;
      }
    }
  }
  bool output = false;
  int left_arm = P - 1;
  int right_arm = 2 * N - P;

  if (up == true) {
    int offset = start_pos;
    for (int i = 0; i < cnt; i++) {
      int current_arm = (offset + i) % (2 * N);
      if (current_arm == left_arm || current_arm == right_arm) {
        output = true;
        break;
      }
    }
  } else {
    int offset = start_pos;
    for (int i = 0; i < cnt; i++) {
      int current_arm = (offset - i + 2 * N) % (2 * N);
      if (current_arm == left_arm || current_arm == right_arm) {
        output = true;
        break;
      }
    }
  }
  if (output) {
    cout << "Dehet YeonJwaJe ^ ~^";
  } else {
    cout << "Hing...NoJam";
  }
}