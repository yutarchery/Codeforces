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

int n, k, a, b;
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

ll solve() {
  cin >> n >> k >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  ll direct = abs(x[a] - x[b]) + abs(y[a] - y[b]);
  ll d1 = 1e16, d2 = 1e16;
  for (int i = 1; i <= k; i++) {
    d1 = min(d1, abs(x[a] - x[i]) + abs(y[a] - y[i]));
    d2 = min(d2, abs(x[b] - x[i]) + abs(y[b] - y[i]));
  }

  return min(direct, d1 + d2);
}

void reset() {
  fill(x + 1, x + n + 1, 0);
  fill(y + 1, y + n + 1, 0);
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