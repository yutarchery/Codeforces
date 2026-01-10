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
int a[int(2e5 + 5)], b[int(2e5 + 5)];

void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 20; i >= 0; i--) {
    int now = (1 << i), val = 0, cnt = 0;
    for (int j = 1; j <= n; j++) {
      if ((a[j] & now) > 0) {
        cnt++;
      }
      if ((b[j] & now) > 0) {
        cnt++;
      }
    }

    if (cnt % 2 == 0) {
      continue;
    }

    for (int j = n; j >= 1; j--) {
      if ((a[j] & now) != (b[j] & now)) {
        if (j % 2 == 1) {
          cout << "Ajisai" << endl;
        } else {
          cout << "Mai" << endl;
        }
        return;
      }
    }
  }

  cout << "Tie" << endl;
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
