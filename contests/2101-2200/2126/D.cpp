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

int n;
ll k, l[int(1e5 + 5)], r[int(1e5 + 5)], reals[int(1e5 + 5)];
pair<Pii, int> p[int(1e5 + 5)];

ll dp[int(1e5 + 5)][2];

ll solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> reals[i];
    p[i] = {{l[i], r[i]}, i};
  }
  sort(p + 1, p + n + 1);

  dp[0][0] = k;
  dp[0][1] = k;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

    int idx = p[i].second;
    dp[i][1] = 0;
    if (l[idx] <= dp[i - 1][0] && dp[i - 1][0] <= r[idx]) {
      dp[i][1] = max(dp[i][1], reals[idx]);
    }
    if (l[idx] <= dp[i - 1][1] && dp[i - 1][1] <= r[idx]) {
      dp[i][1] = max(dp[i][1], reals[idx]);
    }
  }

  return max(dp[n][0], dp[n][1]);
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
