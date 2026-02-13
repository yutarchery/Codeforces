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

vector<Pii> pairs[int(3e5 + 5)];

void prepare() {
  for (int i = 2; i <= int(3e5); i++) {
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        pairs[i].push_back({j, i / j});
      }
    }
  }
  return;
}

int n, a[int(3e5 + 5)];
bool visited[int(3e5 + 5)];
int ans[int(3e5 + 5)];

void solve() {
  cin >> n;
  fill(visited, visited + n + 1, false);
  fill(ans, ans + n + 1, int(1e9));

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    visited[a[i]] = true;
    ans[a[i]] = 1;
  }

  for (int i = 2; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    for (Pii p : pairs[i]) {
      if (visited[p.first] && visited[p.second]) {
        ans[i] = min(ans[i], ans[p.first] + ans[p.second]);
        visited[i] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (visited[i] ? ans[i] : -1) << (i == n ? '\n' : ' ');
  }

  return;
}

int main() {
  prepare();

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
