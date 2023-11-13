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

int n, a[int(1e5 + 5)];
ll c[int(1e5 + 5)], cost[int(1e5 + 5)];
bool visited[int(1e5 + 5)];
vector<int> graph[int(1e5 + 5)];
vector<int> ans;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    cost[a[i]] += c[i];
  }

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  for (int i = 1; i <= n; i++) {
    que.push({cost[i], i});
  }

  while (!que.empty()) {
    Pli now = que.top();
    que.pop();

    int now_node = now.second;

    if (visited[now_node]) {
      continue;
    }

    visited[now_node] = true;
    ans.push_back(now_node);

    int next_node = a[now.second];
    if (!visited[next_node]) {
      cost[next_node] -= c[now_node];
      que.push({cost[next_node], next_node});
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

void reset() {
  fill(a + 1, a + n + 1, 0);
  fill(c + 1, c + n + 1, 0);
  fill(cost + 1, cost + n + 1, 0);
  fill(visited + 1, visited + n + 1, false);
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }
  ans.resize(0);
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