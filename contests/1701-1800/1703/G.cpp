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

int n;
ll k, a[int(1e5 + 5)];

ll b[int(1e5 + 5)][50], dp[int(1e5 + 5)][50];

ll solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i][0] = a[i];
    for (int j = 1; j < 50; j++) {
      b[i][j] = b[i][j - 1] / 2;
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 50; j++) {
      dp[i][j] = -1e18;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 50; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + b[i][j] - k);
      if (j + 1 < 50) {
        dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + b[i][j + 1]);
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 50; j++) {
      ans = max(ans, dp[i][j]);
    }
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
