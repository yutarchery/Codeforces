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

int n, g[805][805];
int ans[1605];
bool visited[1605];

void solve() {
  cin >> n;
  fill(visited + 1, visited + 2 * n + 1, false);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
      visited[g[i][j]] = true;
      ans[i + j] = g[i][j];
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    if (!visited[i]) {
      ans[1] = i;
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    cout << ans[i] << (i == 2 * n ? '\n' : ' ');
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
