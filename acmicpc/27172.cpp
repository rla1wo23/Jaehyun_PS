#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> score;
int arr[1000005] = {0};

void use_f(int idx) {
  int num = v[idx];
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0 && arr[i] > 0) {
      score[idx]--; // 반대 수도 더해줘야지
      score[arr[i]]++;
    }
    if (i * i == num) { // 완전제곱수면 조건을 한 번만 검사해야 함.
      continue;
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
    use_f(i);
  }
  for (int i = 1; i <= N; i++) {
    cout << score[i] << " ";
  }
}