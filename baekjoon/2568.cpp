#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v; // 인덱스, value
int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  vector<int> tmp; // 정답 후보
}