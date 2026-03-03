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
int l[int(3e5 + 5)], r[int(3e5 + 5)];

int par[int(3e5 + 5)];
ll dp[int(3e5 + 5)], dist[int(3e5 + 5)], sum[int(3e5 + 5)];
bool visited[int(3e5 + 5)];

ll make_dp(int idx) {
  if (visited[idx]) {
    return dp[idx];
  }

  visited[idx] = true;
  if (l[idx] == 0 && r[idx] == 0) {
    return dp[idx] = 0;
  }

  ll res = (make_dp(l[idx]) + make_dp(r[idx]) + 4) % MOD;
  return dp[idx] = res;
}

ll make_dist(int idx) {
  if (visited[idx]) {
    return dist[idx];
  }

  visited[idx] = true;
  if (idx == 0) {
    return dist[0] = 0;
  }

  ll res = make_dist(par[idx]) + 1;
  return dist[idx] = res;
}

ll make_sum(int idx) {
  if (visited[idx]) {
    return sum[idx];
  }

  visited[idx] = true;
  if (idx == 0) {
    return sum[0] = 0;
  }

  ll res = (make_sum(par[idx]) + dp[idx]) % MOD;
  return sum[idx] = res;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    par[l[i]] = i;
    par[r[i]] = i;
  }

  fill(visited, visited + n + 1, false);
  for (int i = 1; i <= n; i++) {
    make_dp(i);
  }

  fill(visited, visited + n + 1, false);
  for (int i = 1; i <= n; i++) {
    make_dist(i);
  }

  fill(visited, visited + n + 1, false);
  for (int i = 1; i <= n; i++) {
    make_sum(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << (dist[i] + sum[i]) % MOD << (i == n ? '\n' : ' ');
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
