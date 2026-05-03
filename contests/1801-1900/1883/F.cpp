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

ll n, a[int(1e5 + 5)];

ll cnt_r[int(1e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<ll, bool> visited_l, visited_r;
  fill(cnt_r + 1, cnt_r + n + 2, 0);

  for (int i = n; i >= 1; i--) {
    if (!visited_r[a[i]]) {
      cnt_r[i]++;
    }
    visited_r[a[i]] = true;
  }
  for (int i = n; i >= 1; i--) {
    cnt_r[i] += cnt_r[i + 1];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited_l[a[i]]) {
      continue;
    }
    visited_l[a[i]] = true;
    ans += cnt_r[i];
  }

  return ans;
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
