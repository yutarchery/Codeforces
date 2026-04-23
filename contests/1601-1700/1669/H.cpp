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

int n;
ll k, a[int(2e5 + 5)], cnt[35];

ll solve() {
  cin >> n >> k;
  fill(cnt, cnt + 31, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ll rest = a[i];
    for (int j = 0; j <= 30; j++) {
      if (rest % 2 == 1) {
        cnt[j]++;
      }
      rest /= 2;
    }
  }

  ll ans = 0;
  for (int j = 30; j >= 0; j--) {
    if (k >= (n - cnt[j])) {
      ans += ll(1 << j);
      k -= n - cnt[j];
    }
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
