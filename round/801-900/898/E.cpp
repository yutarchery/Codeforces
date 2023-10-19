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

int t, n;
ll x, a[int(2e5 + 5)];

int solve() {
  ll l = 0, r = int(1e10 + 5);

  while (r - l > 1) {
    ll mid = (l + r) / 2, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += max(0ll, mid - a[i]);
    }

    if (sum <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> x;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }

    cout << solve() << endl;
  }

  return 0;
}