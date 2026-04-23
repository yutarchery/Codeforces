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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m;
char s[55][55], ans[55][55];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }
  }

  for (int j = 1; j <= m; j++) {
    int start = n, cnt = 0;
    for (int i = n; i >= 1; i--) {
      if (s[i][j] == 'o') {
        ans[i][j] = 'o';

        for (int ii = start; ii >= i + 1; ii--) {
          if (cnt > 0) {
            ans[ii][j] = '*';
            cnt--;
          } else {
            ans[ii][j] = '.';
          }
        }
        start = i - 1;
      } else if (s[i][j] == '*') {
        cnt++;
      }
    }

    for (int i = start; i >= 1; i--) {
      if (cnt > 0) {
        ans[i][j] = '*';
        cnt--;
      } else {
        ans[i][j] = '.';
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
