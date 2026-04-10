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

int n, q;
char s[25];
ll a[int(1e4 + 5)];

void solve() {
  cin >> n >> q;

  bool has_b = false;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == 'B') {
      has_b = true;
    }
  }
  for (int i = 1; i <= q; i++) {
    cin >> a[i];
  }

  if (!has_b) {
    for (int i = 1; i <= q; i++) {
      cout << a[i] << '\n';
    }
    return;
  }

  for (int i = 1; i <= q; i++) {
    ll ans = 0;
    int idx = 1;

    while (a[i] > 0) {
      ans++;

      if (s[idx] == 'A') {
        a[i]--;
      } else {
        a[i] /= 2;
      }

      idx++;
      if (idx == n + 1) {
        idx = 1;
      }
    }

    cout << ans << '\n';
  }

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
