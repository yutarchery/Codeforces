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

vector<ll> luckies;

void prepare(ll n = 0) {
  if (n > ll(1e10)) {
    return;
  }

  luckies.emplace_back(10 * n + 4);
  prepare(10 * n + 4);

  luckies.emplace_back(10 * n + 7);
  prepare(10 * n + 7);

  return;
}

ll l, r;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  prepare();
  sort(luckies.begin(), luckies.end());

  cin >> l >> r;

  ll ans = 0;
  for (int i = 0; i < luckies.size(); i++) {
    if (l <= luckies[i]) {
      ans += luckies[i] * (min(luckies[i], r) - l + 1);
      l = luckies[i] + 1;
    }

    if (l > r) {
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}
