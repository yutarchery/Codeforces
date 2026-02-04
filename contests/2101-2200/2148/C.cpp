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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];

int solve() {
  cin >> n >> m;
  int ans = 0, now = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];

    if ((a[i] - a[i - 1]) % 2 == abs(now - b[i])) {
      ans += a[i] - a[i - 1];
    } else {
      ans += a[i] - a[i - 1] - 1;
    }

    now = b[i];
  }

  ans += m - a[n];
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
