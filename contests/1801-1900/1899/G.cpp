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

int n, q, p[int(1e5 + 5)];
vector<int> graph[int(1e5 + 5)];
bool ans[int(1e5 + 5)];
struct query {
  int l, r, i;
};
vector<query> queries[int(1e5 + 5)];

void prepare_graph() {
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return;
}

set<int> indexes[int(1e5 + 5)];
void calc_index(int now_node, int before_node = -1) {
  for (int next_node : graph[now_node]) {
    if (next_node == before_node) {
      continue;
    }
    calc_index(next_node, now_node);

    if (indexes[now_node].size() < indexes[next_node].size()) {
      swap(indexes[now_node], indexes[next_node]);
    }

    for (int i : indexes[next_node]) {
      indexes[now_node].insert(i);
    }
  }

  for (query now_query : queries[now_node]) {
    auto iter = indexes[now_node].lower_bound(now_query.l);
    if (iter != indexes[now_node].end() && (*iter) <= now_query.r) {
      ans[now_query.i] = true;
    } else {
      ans[now_query.i] = false;
    }
  }

  return;
}

void solve() {
  cin >> n >> q;
  prepare_graph();
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    indexes[p[i]].insert(i);
  }
  for (int i = 1; i <= q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    queries[x].push_back({l, r, i});
  }
  calc_index(1);
  for (int i = 1; i <= q; i++) {
    if (ans[i]) {
      YES();
    } else {
      NO();
    }
  }
  return;
}

void reset() {
  for (int i = 1; i <= n; i++) {
    graph[i].clear();
    indexes[i].clear();
  }
  for (int i = 1; i <= q; i++) {
    queries[i].clear();
  }
  fill(ans + 1, ans + q + 1, false);

  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    reset();
  }

  return 0;
}
