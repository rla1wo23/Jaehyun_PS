#include <algorithm>
#include <iostream>
using namespace std;
int arr[505];
int group[505];
int table[505][505];
int find(int k) {
  if (k == arr[k])
    return k;
  return arr[k] = find(arr[k]);
}
void union_set(int a, int b) {
  if (a > b)
    swap(a, b);
  int a_par = find(arr[a]);
  int b_par = find(arr[b]);
  if (a_par == b_par)
    return;
  int num = group[b_par];
  group[a_par] += group[b_par];
  arr[b_par] = a_par;
}
void clearing(int n) {
  for (int i = 0; i < n; i++)
    arr[i] = i;
  fill(group, group + n, 1);
  for (int i = 0; i < n; i++)
    fill(table[i], table[i] + n, 0);
}
int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int n, m;
    cin >> n >> m;
    clearing(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      table[u][v] = 1;
      table[v][u] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (table[i][j]) {
          union_set(i, j);
        }
      }
    }
    int ans = 505;
    for (int i = 0; i < n; i++) {
      cout << "group" << i << ":" << group[i] << "\n";
      if (group[i] >= 3)
        ans = min(ans, group[i]);
    }
    cout << "Case " << tc << ": ";
    if (ans == 505) {
      cout << "impossible\n";
    } else {
      cout << ans << "\n";
    }
  }
}