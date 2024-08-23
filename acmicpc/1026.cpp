#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A[50];
  int B[50];
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(A, A + N);
  sort(B, B + N);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A[i] * B[N - 1 - i];
  }
  cout << ans;
}