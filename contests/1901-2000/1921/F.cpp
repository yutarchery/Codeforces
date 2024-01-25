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

int n, q;
ll s, d, k;
ll a[int(1e5 + 5)], ans[int(2e5 + 5)];

const int b = 300;
ll dp[int(1e5 + 305)][305], sum[int(1e5 + 305)][305];

void solve() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= b; j++) {
      sum[i][j] = sum[i + j][j] + a[i];
      dp[i][j] = dp[i + j][j] + sum[i][j];
    }
  }

  for (int i = 1; i <= q; i++) {
    scanf("%lld %lld %lld", &s, &d, &k);

    if (d <= b) {
      ans[i] = dp[s][d];
      if (s + k * d <= n) {
        ans[i] -= dp[s + k * d][d] + k * sum[s + k * d][d];
      }
    } else {
      for (int j = 0; j < k; j++) {
        ans[i] += ll(j + 1) * a[s + j * d];
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    printf("%lld", ans[i]);
    if (i == q) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return;
}

void reset() {
  fill(a + 1, a + n + 1, 0);
  fill(ans + 1, ans + q + 1, 0);
  for (int i = 1; i <= n; i++) {
    fill(dp[i] + 1, dp[i] + b + 1, 0);
    fill(sum[i] + 1, sum[i] + b + 1, 0);
  }
  return;
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
