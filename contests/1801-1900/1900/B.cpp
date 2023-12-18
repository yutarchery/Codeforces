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

bool dp[305][305][305][3], visited[305][305][305][3];

bool solve(int a, int b, int c, int num) {
  if (visited[a][b][c][num]) {
    return dp[a][b][c][num];
  }

  visited[a][b][c][num] = true;

  if (b == 0 && c == 0) {
    return dp[a][b][c][num] = (num == 0);
  }
  if (c == 0 && a == 0) {
    return dp[a][b][c][num] = (num == 1);
  }
  if (a == 0 && b == 0) {
    return dp[a][b][c][num] = (num == 2);
  }

  bool ans = false;
  if (b >= 1 && c >= 1) {
    ans |= solve(a + 1, b - 1, c - 1, num);
  }
  if (c >= 1 && a >= 1) {
    ans |= solve(a - 1, b + 1, c - 1, num);
  }
  if (a >= 1 && b >= 1) {
    ans |= solve(a - 1, b - 1, c + 1, num);
  }

  return dp[a][b][c][num] = ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    for (int j = 0; j < 3; j++) {
      cout << solve(a, b, c, j);
      if (j == 2) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return 0;
}
