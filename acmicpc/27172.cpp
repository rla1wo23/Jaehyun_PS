#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> score;
int arr[1000005] = {0};

void factoring(int idx) {
  int num = v[idx];
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0 && arr[i] > 0) { // 나눠 떨어지고, i 카드가 존재한다면
      score[idx]--;
      score[arr[i]]++;
      if (i * i == num) {
        continue;
      }
    }
    if (num % i == 0 && arr[num / i] > 0) {
      score[idx]--;
      score[arr[num / i]]++;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  v.resize(N + 1);
  score.resize(N + 1);
  v[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> v[i];
    arr[v[i]] = i;
  }
  for (int i = 1; i <= N; i++) {
    factoring(i);
  }
  for (int i = 1; i <= N; i++) {
    cout << score[i] << " ";
  }
}