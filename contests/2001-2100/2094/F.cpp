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

int n, m, k;
vector<int> ans[int(2e5 + 5)];

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    ans[i].resize(m, 0);
  }

  if (m % k == 0) {
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        for (int j = 0; j < m; j++) {
          ans[i][j] = j % k;
          if (ans[i][j] == 0) {
            ans[i][j] = k;
          }
        }
      } else {
        for (int j = 0; j < m; j++) {
          ans[i][j] = (j + 1) % k;
          if (ans[i][j] == 0) {
            ans[i][j] = k;
          }
        }
      }
    }
  } else {
    int now = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        ans[i][j] = now;
        now++;
        if (now > k) {
          now = 1;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << (j == m - 1 ? '\n' : ' ');
    }
  }

  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
