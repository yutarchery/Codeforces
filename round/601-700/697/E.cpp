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

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % MOD, n / 2);
  } else {
    return my_pow(a, n - 1) * a % MOD;
  }
}

ll frac[1005], rev[1005];
int t, n, k, a[1005];

ll solve() {
  vector<Pll> p;
  int now = a[0], cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      p.push_back({now, cnt});
      now = a[i];
      cnt = 1;
    }
  }

  for (int i = 0; i < p.size(); i++) {
    if (k - p[i].second > 0) {
      k -= p[i].second;
    } else {
      ll ans = frac[p[i].second] * rev[k] % MOD;
      ans *= rev[p[i].second - k];
      return ans % MOD;
    }
  }

  return 0;
}

int main() {
  frac[0] = 1;
  rev[0] = 1;
  for (ll i = 1; i <= 1000; i++) {
    frac[i] = frac[i - 1] * i % MOD;
    rev[i] = my_pow(frac[i], MOD - 2);
  }

  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &k);
    fill(a, a + 1005, 0);
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[j]);
    }
    sort(a, a + n, greater<ll>());
    printf("%lld\n", solve());
  }

  return 0;
}