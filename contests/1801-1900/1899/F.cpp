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

int n, q, d[505];

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> d[i];
  }

  for (int i = 1; i <= n - 1; i++) {
    cout << i << " " << i + 1 << endl;
  }
  int connected = n - 1;
  for (int i = 1; i <= q; i++) {
    if (connected == d[i]) {
      cout << "-1 -1 -1" << endl;
    } else {
      cout << n << " " << connected << " " << d[i] << endl;
      connected = d[i];
    }
  }
  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
