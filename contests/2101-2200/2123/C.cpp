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

int n, a[int(2e5 + 5)];
int pre[int(2e5 + 5)], suf[int(2e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  pre[1] = a[1];
  for (int i = 2; i <= n; i++) {
    pre[i] = min(a[i], pre[i - 1]);
  }

  suf[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    suf[i] = max(a[i], suf[i + 1]);
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == pre[i] || a[i] == suf[i]) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << '\n';

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
