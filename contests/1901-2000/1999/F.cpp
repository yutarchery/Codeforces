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
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

ll fac[int(2e5 + 5)], rev[int(2e5 + 5)];

ll nCk(ll n, ll k, ll mod) {
  ll res = fac[n] * rev[k] % mod;
  res = res * rev[n - k] % mod;
  return res;
}

int t, n, k, a[int(2e5 + 5)], cnt[2];

ll solve() {
  ll ans = 0;
  for (int i = (k + 1) / 2; i <= cnt[1] && k - i >= 0; i++) {
    if (cnt[0] >= k - i) {
      ans += nCk(cnt[1], i, MOD) * nCk(cnt[0], k - i, MOD) % MOD;
      ans %= MOD;
    }
  }

  return ans;
}

int main() {
  fac[0] = 1;
  rev[0] = 1;
  for (ll i = 1; i <= int(2e5); i++) {
    fac[i] = fac[i - 1] * i % MOD;
    rev[i] = my_pow(fac[i], MOD - 2, MOD);
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    printf("%lld\n", solve());
    for (int i = 0; i < 2; i++) {
      cnt[i] = 0;
    }
  }

  return 0;
}
