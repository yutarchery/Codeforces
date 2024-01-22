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

int n, m, a[int(1e5 + 5)];

int cost[int(1e5 + 5)][2], sum[int(1e5 + 5)][2];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n - 2; i++) {
    if (abs(a[i + 1] - a[i]) <= abs(a[i + 1] - a[i + 2])) {
      cost[i][0] = 1;
    } else {
      cost[i][0] = abs(a[i] - a[i + 1]);
    }
  }
  cost[n - 1][0] = 1;

  cost[2][1] = 1;
  for (int i = 3; i <= n; i++) {
    if (abs(a[i - 1] - a[i]) <= abs(a[i - 1] - a[i - 2])) {
      cost[i][1] = 1;
    } else {
      cost[i][1] = abs(a[i] - a[i - 1]);
    }
  }

  for (int i = 1; i <= n; i++) {
    sum[i][1] = sum[i - 1][1] + cost[i][1];
  }
  for (int i = n; i >= 1; i--) {
    sum[i][0] = sum[i + 1][0] + cost[i][0];
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    if (x <= y) {
      cout << sum[y][1] - sum[x][1] << endl;
    } else {
      cout << sum[y][0] - sum[x][0] << endl;
    }
  }

  return;
}

void reset() {
  fill(a, a + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      cost[i][j] = 0;
      sum[i][j] = 0;
    }
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
