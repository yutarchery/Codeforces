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

int t, n, q;
ll x, y, a[int(2e5 + 5)];
map<ll, ll> cnt;

pair<ll, bool> my_sqrt(ll num) {
  if (num < 0) {
    return {0, false};
  }

  ll l = 0, r = 2e9;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (mid * mid <= num) {
      l = mid;
    } else {
      r = mid;
    }
  }

  if (l * l == num) {
    return {l, true};
  } else {
    return {0, false};
  }
}

ll solve() {
  pair<ll, bool> p = my_sqrt(x * x - 4 * y);
  if (!p.second) {
    return 0;
  }

  ll l = (x + p.first), r = (x - p.first);
  if (l % 2 != 0 || r % 2 != 0) {
    return 0;
  }

  l /= 2;
  r /= 2;
  if (l != r) {
    return cnt[l] * cnt[r];
  } else {
    return cnt[l] * (cnt[l] - 1) / 2;
  }
}

void reset() {
  for (int i = 0; i < n; i++) {
    cnt[a[i]] = 0;
  }
  fill(a, a + n, 0);

  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      cnt[a[j]]++;
    }

    cin >> q;
    for (int j = 0; j < q; j++) {
      cin >> x >> y;
      cout << solve();
      if (j == q - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }

    reset();
  }

  return 0;
}