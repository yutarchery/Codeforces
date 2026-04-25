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

int n, x[int(2e5 + 5)];

int l[int(2e5 + 5)], dp[int(2e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }

  fill(l + 1, l + n + 1, 0);
  fill(dp + 1, dp + n + 1, 0);

  map<int, int> before;
  for (int i = 1; i <= n; i++) {
    if (before[x[i]] == 0) {
      l[i] = i;
      dp[i] = 1;
    } else {
      int b = before[x[i]];

      if (dp[b] + 1 - (i - 1 - b) >= 1) {
        dp[i] = dp[b] + 1 - (i - 1 - b);
        l[i] = l[b];
      } else {
        dp[i] = 1;
        l[i] = i;
      }
    }

    before[x[i]] = i;
  }

  int idx = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (ans < dp[i]) {
      ans = dp[i];
      idx = i;
    }
  }
  cout << x[idx] << ' ' << l[idx] << ' ' << idx << '\n';

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
