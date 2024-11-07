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

ll k;

ll my_sqrt(ll num) {
  ll l = 0, r = 1e9 + 5;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (mid * mid <= num) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

ll solve() {
  cin >> k;
  ll now = k + my_sqrt(k), cnt = now - my_sqrt(now);

  while (cnt < k) {
    now++;
    cnt = now - my_sqrt(now);
  }
  return now;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
