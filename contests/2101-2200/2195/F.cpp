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
ll a[3005], b[3005], c[3005];

int order[3005];
int dp1[3005], dp2[3005];

bool my_compare(int i, int j) { return c[i] > c[j]; }

bool is_crossing(int i, int j) {
  if (a[i] == a[j]) {
    return b[i] != b[j];
  }

  return (b[i] - b[j]) * (b[i] - b[j]) - 4 * (a[i] - a[j]) * (c[i] - c[j]) >= 0;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    order[i] = i;
  }
  fill(dp1, dp1 + n + 1, 0);
  fill(dp2, dp2 + n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  sort(order + 1, order + n + 1, my_compare);

  for (int i = 1; i <= n; i++) {
    dp1[order[i]] = 1;
    for (int j = 1; j <= i - 1; j++) {
      if (!is_crossing(order[i], order[j])) {
        dp1[order[i]] = max(dp1[order[i]], dp1[order[j]] + 1);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    dp2[order[i]] = 1;
    for (int j = n; j >= i + 1; j--) {
      if (!is_crossing(order[i], order[j])) {
        dp2[order[i]] = max(dp2[order[i]], dp2[order[j]] + 1);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dp1[i] + dp2[i] - 1 << (i == n ? '\n' : ' ');
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
