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
  return a / g * b;
}

int n;
ll p[int(1e5 + 5)], s[int(1e5 + 5)];
ll ans[int(1e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i + 1 <= n; i++) {
    if (my_gcd(p[i], p[i + 1]) != p[i + 1]) {
      NO();
      return;
    }
  }
  for (int i = n; i - 1 >= 1; i--) {
    if (my_gcd(s[i], s[i - 1]) != s[i - 1]) {
      NO();
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = my_lcm(p[i], s[i]);
  }

  ll now = ans[1];
  for (int i = 1; i <= n; i++) {
    now = my_gcd(ans[i], now);
    if (now != p[i]) {
      NO();
      return;
    }
  }

  now = ans[n];
  for (int i = n; i >= 1; i--) {
    now = my_gcd(ans[i], now);
    if (now != s[i]) {
      NO();
      return;
    }
  }

  YES();
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
