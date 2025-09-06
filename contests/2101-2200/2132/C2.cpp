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

ll num[30], cnt[30];

ll solve() {
  ll n, k;
  cin >> n >> k;
  fill(cnt, cnt + 30, 0);

  while (n > 0) {
    for (ll x = 29; x >= 0; x--) {
      if (n >= num[x]) {
        n -= num[x];
        cnt[x]++;
        k--;
        break;
      }
    }
  }

  if (k < 0) {
    return -1;
  }

  for (ll x = 29; x >= 1; x--) {
    if (cnt[x] == 0) {
      continue;
    }

    if (k >= cnt[x] * 2) {
      k -= cnt[x] * 2;
      cnt[x - 1] += cnt[x] * 3;
      cnt[x] = 0;
    } else if (k >= 2) {
      ll rest = k / 2;
      cnt[x - 1] += rest * 3;
      k -= rest * 2;
      cnt[x] -= rest;
    }
  }

  ll ans = 0;
  for (ll x = 0; x + 1 <= 29; x++) {
    ans += cnt[x] * (num[x + 1] + x * num[x - 1]);
  }

  return ans;
}

int main() {
  num[0] = 1;
  for (int i = 1; i < 30; i++) {
    num[i] = num[i - 1] * 3;
  }

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
