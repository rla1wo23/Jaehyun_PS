#include <iostream>
#include <vector>
using namespace std;
int un[51] = {0};
int find(int k) {
  if (un[k] == k) { // 내가 내 조상이면
    return k;
  } else {
    return un[k] = find(un[k]);
  }
}
void uni(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);
  if (rootA < rootB) {
    un[rootB] = rootA;
  } else {
    un[rootA] = rootB;
  }
}

int main() {
  for (int i = 0; i < 51; i++) {
    un[i] = i;
  }
  int N, M;
  cin >> N >> M;
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int k;
    cin >> k;
    un[k] = 0;
  }
  vector<vector<int>> v(M);
  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++) {
      int p;
      cin >> p; // 해당 파티에 참석한 사람
      v[i].push_back(p);
      if (j > 0) {
        uni(p, v[i][0]);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    bool connected = false;
    for (int j = 0; j < v[i].size(); j++) {
      if (find(v[i][j]) == 0) {
        connected = true;
        break;
      }
    }
    if (connected) {
      cnt++;
    }
  }
  cout << M - cnt << "\n";
}