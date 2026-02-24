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

int n, m, u, v;

vector<int> graph[int(2e5 + 5)];
int group[int(2e5 + 5)];
vector<int> nodes[int(2e5 + 5)];

int find_group(int u) {
  if (group[u] == u) {
    return u;
  } else {
    int gu = find_group(group[u]);
    return group[u] = gu;
  }
}

void unite(int u, int v) {
  int gu = find_group(u), gv = find_group(v);

  group[u] = min(gu, gv);
  group[v] = min(gu, gv);
  group[max(gu, gv)] = min(gu, gv);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);

    unite(u, v);
  }

  for (int i = 1; i <= n; i++) {
    int g = find_group(i);
    nodes[g].push_back(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (nodes[i].size() >= 3) {
      bool flag = true;

      for (int j : nodes[i]) {
        if (graph[j].size() != 2) {
          flag = false;
        }
      }

      if (flag) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
