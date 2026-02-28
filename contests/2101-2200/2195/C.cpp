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

int n, a[int(3e5 + 5)];

int dp[int(3e5 + 5)][2];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][1] = 1e9;

  for (int i = 1; i <= n; i++) {
    if (a[i] + a[i - 1] == 7 || a[i] == a[i - 1]) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
    } else {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
    }
  }

  return min(dp[n][0], dp[n][1]);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
