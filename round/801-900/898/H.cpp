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

int t, n, a, b;
vector<int> graph[int(2e5 + 5)];
bool loop[int(2e5 + 5)];

void input() {
  for (int i = 1; i <= n; i++) {
    graph[i] = {};
  }
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return;
}

void find_loop() {
  fill(loop, loop + n + 1, false);
  int dist[n + 5] = {};
  bool visited[n + 5] = {};
  int before_node[n + 5] = {};
  int loop_start;

  queue<int> que;
  que.push(1);
  visited[1] = true;

  priority_queue<Pii> loop_que;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    bool flag = false;
    for (int next : graph[now]) {
      if (!visited[next]) {
        visited[next] = true;
        before_node[next] = now;
        que.push(next);
        dist[next] = dist[now] + 1;
      } else {
        if (before_node[now] != next) {
          flag = true;
          loop_que.push({dist[now], now});
          loop_que.push({dist[next], next});
          break;
        }
      }
    }

    if (flag) {
      break;
    }
  }

  fill(visited, visited + n + 1, false);
  while (!loop_que.empty()) {
    Pii now = loop_que.top();
    loop_que.pop();

    if (visited[now.second]) {
      break;
    }
    visited[now.second] = true;
    loop[now.second] = true;
    loop_que.push({dist[before_node[now.second]], before_node[now.second]});
  }

  return;
}

Pii calc_b_dist() {
  if (loop[b]) {
    return {0, b};
  }

  bool visited[n + 5] = {};
  int dist[n + 5] = {};

  queue<int> que;
  que.push(b);
  visited[b] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      if (visited[next]) {
        continue;
      }

      visited[next] = true;
      dist[next] = dist[now] + 1;
      que.push(next);

      if (loop[next]) {
        return {dist[next], next};
      }
    }
  }

  return {0, 0};
}

void solve() {
  input();
  find_loop();

  Pii b_goal = calc_b_dist();

  int dist[n + 5] = {};
  bool visited[n + 5] = {};

  queue<int> que;
  que.push(a);
  visited[a] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      if (visited[next]) {
        continue;
      }

      visited[next] = true;
      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }

  if (dist[b_goal.second] <= b_goal.first) {
    NO();
  } else {
    YES();
  }

  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> a >> b;
    solve();
  }

  return 0;
}