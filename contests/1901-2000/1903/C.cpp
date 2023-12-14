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
ll a[int(1e5 + 5)], total[int(1e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    total[i] = total[i - 1] + a[i];
  }

  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ans += i * a[i];
  }

  for (int i = n - 1; i >= 1; i--) {
    ans = max(ans, ans - (total[n] - total[i]));
  }

  return ans;
}

void reset() {
  fill(a, a + n + 1, 0);
  fill(total, total + n + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
    reset();
  }
  return 0;
}
