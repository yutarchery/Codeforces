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

int n, m, val[int(2e5 + 5)][3];
int f[15];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> val[i][j];
    }
    sort(val[i], val[i] + 3);
  }

  for (int i = 1; i <= m; i++) {
    if (f[n] <= val[i][0] && f[n] + f[n - 1] <= val[i][2]) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;

  return;
}

int main() {
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= 10; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
