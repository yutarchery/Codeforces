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
char a[20], b[20], c[20];

void solve() {
  cin >> n;

  string ans = "";
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= m; i++) {
    if (c[i] == 'V') {
      ans = b[i] + ans;
    } else {
      ans = ans + b[i];
    }
  }

  cout << ans << endl;
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
