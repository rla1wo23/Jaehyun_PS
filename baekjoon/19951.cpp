#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int field[100005];
  for (int i = 1; i <= N; i++) {
    cin >> field[i];
  }
  int sum[100005];
  for (int i = 0; i <= N; i++) {
    sum[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int st, en, var;
    cin >> st >> en >> var;
    sum[st] += var;
    sum[en + 1] -= var;
  }
  int cal_sum = 0;
  for (int i = 1; i <= N; i++) {
    cal_sum += sum[i];
    field[i] += cal_sum;
  }
  for (int i = 1; i <= N; i++) {
    cout << field[i] << " ";
  }
}