#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int people[51] = {0};
// 이사람을 다시 만날 일이 없으면,과장해도 된다.
// 진실을 아는 사람 없다고 바로 말해도 되는가? =>아님. 이사람이 진실자랑 나중에
// 진실을 아는 자랑 언젠가 파티에 같이 참석할 것인지 아닌지
// 여부가 중요하다. 진실을 무조건 말해야 되는 경우에는 당연히 진실자가 된다.
// 과장 과장 가능
int main() {
  int N, M;
  cin >> N >> M;
  int tp;
  cin >> tp;
  while (tp--) {
    int i;
    cin >> i;
    people[i] = -1;
  }
  int cnt = 0;
  vector<vector<int>> lpt(M);   // 거짓파티
  for (int i = 0; i < M; i++) { // M개의 파티
    int pp;                     // 파티 참여인
    cin >> pp;
    bool truth = false;
    vector<int> v;
    for (int i = 0; i < pp; i++) {
      int idx;
      cin >> idx;
      v.push_back(idx);
      if (people[idx] == -1) {
        truth = true;
        cnt++;
      }
    }
    if (truth = true) {
      for (int i = 0; i < pp; i++) {
        people[v[i]] = -1;
      }
    } else {
    }
  }
}