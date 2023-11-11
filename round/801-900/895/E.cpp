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

int n, q, tp, l, r, g;
string s;
ll a[int(1e5 + 5)], dp[int(1e5 + 5)], val0, val1;
vector<ll> ans;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = dp[i - 1] ^ a[i];
  }
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '0') {
      val0 ^= a[i];
    } else {
      val1 ^= a[i];
    }
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> tp;
    if (tp == 1) {
      cin >> l >> r;
      val0 ^= dp[l - 1] ^ dp[r];
      val1 ^= dp[l - 1] ^ dp[r];
    } else {
      cin >> g;
      if (g == 0) {
        ans.push_back(val0);
      } else {
        ans.push_back(val1);
      }
    }
  }

  int as = ans.size();
  for (int i = 0; i < as; i++) {
    cout << ans[i];
    if (i == as - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

void reset() {
  fill(a, a + n + 1, 0);
  fill(dp, dp + n + 1, 0);
  val0 = 0;
  val1 = 0;
  ans.resize(0);
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
    reset();
  }

  return 0;
}