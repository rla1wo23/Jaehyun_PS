#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define X second.first
#define Y second.second
using namespace std;
int arr[100005];
vector<pair<int, pair<int, int>>> v;
int find(int k) {
  if (k == arr[k]) {
    return k;
  } else {
    return arr[k] = find(arr[k]);
  }
}
void uni(int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  arr[find(y)] = arr[find(x)];
  arr[y] = arr[find(x)];
}
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.X < b.X;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  v.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    v[i] = {i, {x1, x2}};
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 1; i <= N; i++) {
    arr[i] = i;
  }
  int re = v[1].Y;
  for (int i = 2; i <= N; i++) {
    if (re >= v[i].X) {
      uni(v[i - 1].first, v[i].first); // 인덱스들끼리 유니온
    }
    re = max(re, v[i].Y);
  }
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << (find(l) == find(r)) << "\n";
  }
}