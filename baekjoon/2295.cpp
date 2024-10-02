#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> sums;
unordered_map<int, int> save_space;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<long long> v(N);
  vector<int> cand_vector;
  unordered_map<int, int> cand;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    cand[v[i]] = 1;
    cand_vector.push_back(v[i]);
  }
  sort(v.begin(), v.end());
  // Step1:두개의 합을 다 저장하는 단계
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sums.push_back(v[i] + v[j]);
    }
  }
  // Step2:두개의 합의 반대를 저장
}