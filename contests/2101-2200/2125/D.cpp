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

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return my_pow(a, n - 1, mod) * a % mod;
  }
}

int n, m;
int l[int(2e5 + 5)], r[int(2e5 + 5)];
ll p[int(2e5 + 5)], q[int(2e5 + 5)];
Pii l_idx[int(2e5 + 5)];

ll dp[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> p[i] >> q[i];
    l_idx[i] = {l[i], i};
  }
  sort(l_idx + 1, l_idx + n + 1);

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int idx = l_idx[i].second;
    ll now = p[idx] * my_pow(q[idx] - p[idx], MOD2 - 2, MOD2) % MOD2;
    dp[r[idx]] += dp[l[idx] - 1] * now % MOD2;
    dp[r[idx]] %= MOD2;
  }

  ll sum = 1;
  for (int i = 1; i <= n; i++) {
    sum *= q[i] - p[i];
    sum %= MOD2;
    sum *= my_pow(q[i], MOD2 - 2, MOD2);
    sum %= MOD2;
  }

  cout << dp[m] * sum % MOD2 << endl;

  return 0;
}
