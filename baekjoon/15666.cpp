#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool is_used[8];
vector<int> space;
vector<int> output(8);
int N, M;
int len = 0;
void func(int k, int bef) {
  if (k == M) {
    for (int i = 0; i < M; i++) {
      cout << output[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i < N; i++) {
    if (bef > space[i])
      continue;
    is_used[i] = true;
    output[k] = space[i];
    func(k + 1, space[i]);
    is_used[i] = false;
  }
}

int main() {
  cin >> N >> M;
  unordered_map<int, int> um;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    if (um[k] == 0) {
      space.push_back(k);
      um[k] = 1;
      len++;
    }
  }
  N = len;
  sort(space.begin(), space.end());
  func(0, -1);
}