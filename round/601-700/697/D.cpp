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

int t, n, m;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
Pll p[int(2e5 + 5)];

int solve() {
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
  }
  if (sum < m) {
    return -1;
  }

  int ans = 1e9, now_cost = 0;
  ll now_sum = 0;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  for (int i = 1; i <= n; i++) {
    now_sum += p[i].first;
    now_cost += p[i].second;

    if (p[i].second == 2) {
      que.push(p[i].first);
    }
    if (now_sum < m) {
      continue;
    }

    while (!que.empty()) {
      ll q = que.top();
      if (now_sum - q >= m) {
        que.pop();
        now_sum -= q;
        now_cost -= 2;
      } else {
        break;
      }
    }

    ans = min(ans, now_cost);
  }

  return ans;
}

int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &m);
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &a[j]);
    }
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &b[j]);
    }
    for (int j = 1; j <= n; j++) {
      p[j] = {a[j], b[j]};
    }
    sort(p + 1, p + n + 1, greater<Pll>());

    printf("%d\n", solve());
  }

  return 0;
}