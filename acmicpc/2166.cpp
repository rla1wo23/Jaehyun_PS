#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<long double, long double>> v;

long double shoe_lace(int a, int b, int c) {
  long double sum = v[a].first * v[b].second + v[b].first * v[c].second +
                    v[c].first * v[a].second;
  long double sub = v[a].second * v[b].first + v[b].second * v[c].first +
                    v[c].second * v[a].first;
  return 0.5 * (sum - sub);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long double N;
  cin >> N;
  v.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i].first >> v[i].second;
  }
  cout << fixed;
  cout.precision(1);
  long double ans = 0.0;

  for (int i = 2; i < N; i++) {
    ans += shoe_lace(0, i - 1, i);
  }

  cout << abs(ans);
}
