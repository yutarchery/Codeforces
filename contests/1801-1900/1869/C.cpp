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

int n, m;
vector<int> ans[int(2e5 + 5)];

void solve() {
  cin >> n >> m;

  if (m == 1) {
    cout << 0 << endl;
  } else {
    cout << min(n + 1, m) << endl;
  }

  ans[1].resize(m + 1);
  ans[1][1] = m - 1;
  for (int j = 2; j <= m; j++) {
    ans[1][j] = j - 2;
  }

  for (int i = 2; i <= n; i++) {
    ans[i].resize(m + 1);

    if (ans[i - 1][m] == 0) {
      for (int j = 1; j <= m; j++) {
        ans[i][j] = ans[i - 1][j];
      }
    } else {
      for (int j = 1; j <= m; j++) {
        ans[i][j] = ans[i - 1][j] - 1;
        if (ans[i][j] < 0) {
          ans[i][j] += m;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j];
      if (j == m) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}