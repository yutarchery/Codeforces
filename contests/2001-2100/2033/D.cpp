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
ll a[int(3e5 + 5)], sum[int(3e5 + 5)], dp[int(3e5 + 5)];
map<ll, bool> visited;
map<ll, int> idx;

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  visited[0] = true;
  for (int i = 1; i <= n; i++) {
    if (!visited[sum[i]]) {
      visited[sum[i]] = true;
      idx[sum[i]] = i;
      dp[i] = dp[i - 1];
    } else {
      dp[i] = max(dp[i - 1], dp[idx[sum[i]]] + 1);
      idx[sum[i]] = i;
    }
  }

  return dp[n];
}

void reset() {
  fill(a, a + n + 1, 0);
  fill(dp, dp + n + 1, 0);
  visited = {};
  idx = {};
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
