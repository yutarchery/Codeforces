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

int n, m;
vector<Pli> graph[1005];
ll s[1005], ans[1005], dist[1005][1005];
bool visited[1005];

void calc_dist(int start) {
  fill(visited + 1, visited + n + 1, false);
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, start});

  while (!que.empty()) {
    Pli now = que.top();
    que.pop();

    if (visited[now.second]) {
      continue;
    }
    visited[now.second] = true;
    dist[start][now.second] = now.first;

    for (Pli next : graph[now.second]) {
      if (!visited[next.second]) {
        que.push({now.first + next.first, next.second});
      }
    }
  }
  return;
}

ll solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
    graph[v].push_back({w, u});
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    calc_dist(i);
  }
  fill(visited + 1, visited + n + 1, false);

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, 1});
  while (!que.empty()) {
    Pli now = que.top();
    que.pop();

    if (visited[now.second]) {
      continue;
    }
    visited[now.second] = true;
    ans[now.second] = now.first;

    for (int j = 1; j <= n; j++) {
      if (visited[j]) {
        continue;
      }
      que.push({now.first + s[now.second] * dist[now.second][j], j});
    }
  }

  return ans[n];
}

void reset() {
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }
  fill(s + 1, s + n + 1, 0);
  fill(ans + 1, ans + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    fill(dist[i] + 1, dist[i] + n + 1, 0);
  }
  fill(visited + 1, visited + n + 1, false);
  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
