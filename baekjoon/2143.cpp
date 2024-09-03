#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
long long A[1005];
long long B[1005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T, n, m;
  cin >> T >> n;
  long long sum = 0;
  A[0] = 0;
  B[0] = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    sum += a;
    A[i + 1] = sum;
  }
  cin >> m;
  sum = 0;
  for (int i = 0; i < m; i++) {
    long long a;
    cin >> a;
    sum += a;
    B[i + 1] = sum;
  }
  unordered_map<long long, long long> um;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      um[A[j] - A[i]]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j <= m; j++) {
      ans += um[T - (B[j] - B[i])];
    }
  }
  cout << ans;
}