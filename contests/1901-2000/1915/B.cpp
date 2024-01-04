#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

char s[3][3];

char solve() {
  int row;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> s[i][j];
      if (s[i][j] == '?') {
        row = i;
      }
    }
  }

  bool visited[3] = {};
  for (int j = 0; j < 3; j++) {
    if (s[row][j] == '?') {
      continue;
    }
    visited[s[row][j] - 'A'] = true;
  }

  for (char i = 'A'; i <= 'C'; i++) {
    if (!visited[i - 'A']) {
      return i;
    }
  }

  return 0;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}
