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

int n, m;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
ll sum[int(2e5 + 5)][2];

ll solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + m + 1, greater<ll>());

  for (int i = 1; i <= n; i++) {
    sum[i][0] = sum[i - 1][0] + abs(a[i] - b[i]);
    sum[i][1] = sum[i - 1][1] + abs(a[i] - b[i + m - n]);
  }

  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, sum[i][0] + (sum[n][1] - sum[i][1]));
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}
