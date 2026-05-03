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

int n, k, a[int(1e5 + 5)];

int dp[int(1e5 + 5)][5];

int solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < k; j++) {
      dp[i][j] = int(1e9);
    }
  }

  for (int j = 0; j < k; j++) {
    dp[1][(a[1] + j) % k] = j;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      for (int jj = 0; jj < k; jj++) {
        dp[i][(j * (a[i] + jj)) % k] =
            min(dp[i - 1][j] + jj, dp[i][(j * (a[i] + jj)) % k]);
      }
    }
  }

  return dp[n][0];
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
