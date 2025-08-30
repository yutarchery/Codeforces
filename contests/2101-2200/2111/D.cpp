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
multiset<int> mst[6];
int ans[int(1e5 + 5)][6];

void solve() {
  for (int j = 0; j < 6; j++) {
    mst[j] = {};
  }

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    for (int j = 0; j < 6; j++) {
      mst[j].insert(a[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      if ((i % 2 + j % 2) % 2 == 0) {
        auto iter = mst[j].begin();
        ans[i][j] = *iter;
        mst[j].erase(iter);
      } else {
        auto iter = mst[j].end();
        iter--;
        ans[i][j] = *iter;
        mst[j].erase(iter);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      cout << ans[i][j] << (j == 5 ? '\n' : ' ');
    }
  }

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
