#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int N, M;
unordered_map<int, int> um;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    um[k]++;
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    cout << um[k] << " ";
  }
}