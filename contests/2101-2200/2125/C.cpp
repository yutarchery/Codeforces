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

ll l, r;
const ll primes[4] = {2, 3, 5, 7};

ll calc(ll num) {
  ll ans = 0;
  for (int i = 0; i < 16; i++) {
    int cnt = 0, rest = i;
    ll now = 1;
    for (int j = 0; j < 4; j++) {
      if (rest % 2 == 1) {
        cnt++;
        now *= primes[j];
      }
      rest /= 2;
    }

    if (cnt % 2 == 0) {
      ans += num / now;
    } else {
      ans -= num / now;
    }
  }

  return ans;
}

ll solve() {
  cin >> l >> r;
  return calc(r) - calc(l - 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
