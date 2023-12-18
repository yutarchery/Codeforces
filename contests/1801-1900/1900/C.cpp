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
string s;
int l[int(3e5 + 5)], r[int(3e5 + 5)];

int dp[int(3e5 + 5)];
bool visited[int(3e5 + 5)];

int dfs(int node) {
  if (visited[node]) {
    return dp[node];
  }

  visited[node] = true;

  if (l[node] == 0 && r[node] == 0) {
    return dp[node] = 0;
  }

  int ans = 1e9;
  if (l[node] != 0) {
    if (s[node - 1] == 'L') {
      ans = min(ans, dfs(l[node]));
    } else {
      ans = min(ans, dfs(l[node]) + 1);
    }
  }
  if (r[node] != 0) {
    if (s[node - 1] == 'R') {
      ans = min(ans, dfs(r[node]));
    } else {
      ans = min(ans, dfs(r[node]) + 1);
    }
  }

  return dp[node] = ans;
}

int solve() {
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }

  return dfs(1);
}

void reset() {
  fill(dp + 1, dp + n + 1, 0);
  fill(visited + 1, visited + n + 1, false);
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
