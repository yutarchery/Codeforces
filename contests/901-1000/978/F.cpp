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

int n, k, r[int(2e5 + 5)], x[int(2e5 + 5)], y[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
Pii r_idx[int(2e5 + 5)];
int ans[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    r_idx[i] = {r[i], i};
  }
  sort(r_idx + 1, r_idx + n + 1);

  for (int i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
    graph[x[i]].emplace_back(y[i]);
    graph[y[i]].emplace_back(x[i]);
  }

  int cnt = 0;
  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (r_idx[i].first != r_idx[i - 1].first) {
      while (!que.empty()) {
        int q = que.front();
        que.pop();
        cnt++;
        visited[q] = true;
      }
    }

    ans[r_idx[i].second] = cnt;
    for (int j : graph[r_idx[i].second]) {
      if (visited[j]) {
        ans[r_idx[i].second]--;
      }
    }
    que.push(r_idx[i].second);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
