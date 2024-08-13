#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int N;
int arr[1000001];
int index_checker[1000001]; // 해당 리스트의 인덱싱 관리용, 앞 좌표 기록
vector<int> v;              // 후보군 리스트 관리용
vector<int> v_idx; // 후보군 리스트의 arr상의 인덱스 관리용

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  v.push_back(arr[0]);
  v_idx.push_back(0);
  index_checker[0] = -1;
  int cnt = 0;
  for (int i = 1; i < N; i++) {
    if (arr[i] > v[cnt]) {
      v.push_back(arr[i]);
      v_idx.push_back(i);
      index_checker[i] = v_idx[cnt];
      cnt++;
    } else {
      int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
      v[pos] = arr[i];
      v_idx[pos] = i;
      if (pos > 0) {
        index_checker[i] = v_idx[pos - 1];
      } else {
        index_checker[i] = -1;
      }
    }
  }
  int idx = v_idx[cnt];
  cout << v.size() << "\n";
  stack<int> s;
  while (true) {
    s.push(arr[idx]);
    if (index_checker[idx] == -1) {
      break;
    }
    idx = index_checker[idx];
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}