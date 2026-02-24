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

int n;
ll a[1005];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int turn = 0, l = 1, r = n;
  ll ans_l = 0, ans_r = 0, border = 0, now = 0;

  while (l <= r) {
    if (now == 0) {
      turn++;
    }

    if (turn % 2 == 1) {
      ans_l += a[l];
      now += a[l];
      l++;

      if (now > border) {
        border = now;
        now = 0;
      }
    } else {
      ans_r += a[r];
      now += a[r];
      r--;

      if (now > border) {
        border = now;
        now = 0;
      }
    }
  }

  cout << turn << " " << ans_l << " " << ans_r << endl;

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
