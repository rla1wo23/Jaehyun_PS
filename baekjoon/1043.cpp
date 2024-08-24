#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int people[51] = {0}; // 1이면 진실을 아는 사람
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  int tp; // 최초 진실러
  cin >> tp;
  while (tp--) {
    int i;
    cin >> i;
    people[i] = 1;
  }
  vector<vector<int>> v(M); // 파티 정보
  int cnt = 0;
  bool party_num[51] = {false};
  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;
    bool true_party = false;
    for (int j = 0; j < num; j++) {
      int k;
      cin >> k;
      v[i].push_back(k);
      if (people[k] == 1) {
        true_party = true;
      }
    }
    if (true_party) {
      cnt++;
      party_num[i] = true;
      for (int j = 0; j < num; j++) {
        people[v[i][j]] = 1;
      }
    }
  }
  int b_cnt = 0;
  while (b_cnt != cnt) {
    b_cnt = cnt;
    for (int i = 0; i < M; i++) {
      if (party_num[i])
        continue;
      bool true_party = false;
      for (int j = 0; j < v[i].size(); j++) {
        if (people[v[i][j]] == 1) {
          true_party = true;
          party_num[i] = true;
        }
      }
      if (true_party) {
        cnt++;
        for (int j = 0; j < v[i].size(); j++) {
          people[v[i][j]] = 1;
        }
      }
    }
  }
  cout << M - cnt;
}