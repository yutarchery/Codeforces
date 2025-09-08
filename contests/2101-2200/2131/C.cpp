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

int n, k, a[int(2e5 + 5)], b[int(2e5 + 5)];
map<int, int> cnt_a, cnt_b;

void solve() {
  cnt_a = {};
  cnt_b = {};

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt_a[min(a[i] % k, k - a[i] % k)]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    cnt_b[min(b[i] % k, k - b[i] % k)]++;
  }

  for (int i = 1; i <= n; i++) {
    int idx = min(a[i] % k, k - a[i] % k);
    if (cnt_a[idx] != cnt_b[idx]) {
      NO();
      return;
    }
  }

  YES();
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
