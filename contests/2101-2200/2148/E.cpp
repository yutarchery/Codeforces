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

int n, k, a[int(2e5 + 5)], b[int(2e5 + 5)];

ll solve() {
  cin >> n >> k;

  map<int, int> cnt, valid;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] % k != 0) {
      return 0;
    }
    valid[a[i]] = cnt[a[i]] / k;
  }

  int r = 0;
  ll ans = 0;
  map<int, int> now;
  for (int i = 1; i <= n; i++) {
    while (r < n) {
      if (now[a[r + 1]] >= valid[a[r + 1]]) {
        break;
      }
      r++;
      now[a[r]]++;
    }

    ans += r - i + 1;
    now[a[i]]--;
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
