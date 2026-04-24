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

int n, a[4005];
char s[4005];

vector<int> graph[4005];
int cnt_b[4005], cnt_w[4005];
bool visited[4005];

void dfs(int node = 1) {
  if (visited[node]) {
    return;
  }

  visited[node] = true;
  if (s[node] == 'B') {
    cnt_b[node]++;
  } else {
    cnt_w[node]++;
  }

  for (int next : graph[node]) {
    dfs(next);
    cnt_b[node] += cnt_b[next];
    cnt_w[node] += cnt_w[next];
  }

  return;
}

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }
  fill(cnt_b + 1, cnt_b + n + 1, 0);
  fill(cnt_w + 1, cnt_w + n + 1, 0);
  fill(visited + 1, visited + n + 1, false);

  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    graph[a[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  dfs();

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt_b[i] == cnt_w[i]) {
      ans++;
    }
  }
  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
