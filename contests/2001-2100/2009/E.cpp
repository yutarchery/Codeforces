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

int t;
ll n, k;

ll calc_val(ll num) {
  ll sum_1 = (k + num) * (num - k + 1) / 2;
  ll sum_2 = ((num + 1) + (k + n - 1)) * ((k + n - 1) - num) / 2;
  return abs(sum_1 - sum_2);
}

ll solve() {
  scanf("%lld %lld", &n, &k);

  ll l = k, r = k + n - 1;
  while (r - l > 2) {
    ll m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
    if (calc_val(m1) <= calc_val(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }

  ll ans = 1e18;
  for (ll i = l; i <= r; i++) {
    ans = min(ans, calc_val(i));
  }
  return ans;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", solve());
  }

  return 0;
}
