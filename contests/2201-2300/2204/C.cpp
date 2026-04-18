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

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

ll my_lcm(ll a, ll b) {
  ll g = my_gcd(a, b);
  return (a / g) * b;
}

void solve() {
  ll a, b, c, m;
  cin >> a >> b >> c >> m;

  ll ab = my_lcm(a, b), bc = my_lcm(b, c), ca = my_lcm(c, a);
  ll abc = my_lcm(ab, c);

  ll ans_a = 6 * (m / a) - 3 * (m / ab + m / ca) + 2 * (m / abc);
  ll ans_b = 6 * (m / b) - 3 * (m / ab + m / bc) + 2 * (m / abc);
  ll ans_c = 6 * (m / c) - 3 * (m / bc + m / ca) + 2 * (m / abc);

  cout << ans_a << " " << ans_b << " " << ans_c << '\n';
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
