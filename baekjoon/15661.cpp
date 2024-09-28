#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> team1;
int table[25][25];
int ans = 1e9;

void calc() {
  vector<int> other;
  for (int i = 0; i < N; i++) {
    if (find(team1.begin(), team1.end(), i) == team1.end()) {
      other.push_back(i);
    }
  }
  int team1_point = 0, team2_point = 0;
  for (int i = 0; i < team1.size(); i++) {
    for (int j = i + 1; j < team1.size(); j++) {
      team1_point += table[team1[i]][team1[j]] + table[team1[j]][team1[i]];
    }
  }
  for (int i = 0; i < other.size(); i++) {
    for (int j = i + 1; j < other.size(); j++) {
      team2_point += table[other[i]][other[j]] + table[other[j]][other[i]];
    }
  }
  ans = min(ans, abs(team1_point - team2_point));
}
void back_track(int last) {
  if (team1.size() == N) {
    return;
  }
  for (int i = last + 1; i < N; i++) {
    team1.push_back(i);
    calc();
    back_track(i);
    team1.pop_back();
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> table[i][j];
    }
  }

  back_track(-1);

  cout << ans;
}
