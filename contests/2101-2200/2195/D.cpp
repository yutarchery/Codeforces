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
ll f[int(3e5 + 5)];

ll ans[int(3e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }

  for (int i = 1; i + 2 <= n; i++) {
    ans[i + 1] = ((f[i] - f[i + 1]) - (f[i + 1] - f[i + 2])) / 2;
  }
  ans[1] = f[n];
  for (int i = 2; i <= n - 1; i++) {
    ans[1] -= ans[i] * abs(n - i);
  }
  ans[1] /= ll(n - 1);

  ans[n] = f[1];
  for (int i = 2; i <= n - 1; i++) {
    ans[n] -= ans[i] * ll(i - 1);
  }
  ans[n] /= ll(n - 1);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
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
