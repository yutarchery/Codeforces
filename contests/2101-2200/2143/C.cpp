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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, u[int(2e5 + 5)], v[int(2e5 + 5)];
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int cnt[int(2e5 + 5)], p[int(2e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }

  fill(cnt + 1, cnt + n + 1, 0);
  for (int i = 1; i <= n - 1; i++) {
    cin >> u[i] >> v[i] >> x[i] >> y[i];
    if (x[i] >= y[i]) {
      graph[u[i]].emplace_back(v[i]);
      cnt[v[i]]++;
    } else {
      graph[v[i]].emplace_back(u[i]);
      cnt[u[i]]++;
    }
  }

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      que.push(i);
    }
  }

  int now = n;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    p[q] = now;
    now--;

    for (int next : graph[q]) {
      cnt[next]--;
      if (cnt[next] == 0) {
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << p[i] << (i == n ? '\n' : ' ');
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
