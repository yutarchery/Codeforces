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

int t, n, m, h, u, v, a;
ll w;

vector<Pli> graph[int(4e5 + 5)];
ll dist_1[int(4e5 + 5)], dist_n[int(4e5 + 5)];
bool visited_1[int(4e5 + 5)], visited_n[int(4e5 + 5)];

void prepare() {
  scanf("%d %d %d", &n, &m, &h);
  for (int i = 1; i <= h; i++) {
    scanf("%d", &a);
    graph[a].push_back({0, n + a});
    graph[n + a].push_back({0, a});
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %lld", &u, &v, &w);
    graph[u].push_back({w, v});
    graph[v].push_back({w, u});
    graph[n + u].push_back({w / 2, n + v});
    graph[n + v].push_back({w / 2, n + u});
  }

  return;
}

ll solve() {
  prepare();

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited_1[q.second]) {
      continue;
    }
    visited_1[q.second] = true;
    dist_1[q.second] = q.first;
    for (Pli next : graph[q.second]) {
      if (visited_1[next.second]) {
        continue;
      }
      que.push({q.first + next.first, next.second});
    }
  }

  que.push({0, n});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited_n[q.second]) {
      continue;
    }
    visited_n[q.second] = true;
    dist_n[q.second] = q.first;
    for (Pli next : graph[q.second]) {
      if (visited_n[next.second]) {
        continue;
      }
      que.push({q.first + next.first, next.second});
    }
  }

  ll ans = 1e16;
  for (int i = 1; i <= n; i++) {
    if (visited_1[i] && visited_n[i]) {
      ll d1 = dist_1[i], dn = dist_n[i];
      if (visited_1[i + n]) {
        d1 = min(d1, dist_1[i + n]);
      }
      if (visited_n[i + n]) {
        dn = min(dn, dist_n[i + n]);
      }
      ans = min(ans, max(d1, dn));
    }
  }

  if (ans == 1e16) {
    return -1;
  } else {
    return ans;
  }
}

void reset() {
  for (int i = 1; i <= n * 2; i++) {
    graph[i].resize(0);
  }
  fill(visited_1, visited_1 + n * 2 + 1, false);
  fill(visited_n, visited_n + n * 2 + 1, false);
  fill(dist_1, dist_1 + n * 2 + 1, 0);
  fill(dist_n, dist_n + n * 2 + 1, 0);

  return;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", solve());
    reset();
  }

  return 0;
}
