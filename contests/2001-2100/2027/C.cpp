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

ll n, a[int(3e5 + 5)];
map<ll, vector<ll>> mp;
map<ll, bool> visited;

ll solve() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    mp[a[i] + i - 1].push_back(a[i] + (i - 1) * 2);
  }

  ll ans = 0;
  queue<ll> que;
  que.push(n);
  visited[n] = true;
  while (!que.empty()) {
    ll q = que.front();
    que.pop();
    ans = max(ans, q);
    for (ll v : mp[q]) {
      if (!visited[v]) {
        visited[v] = true;
        que.push(v);
      }
    }
  }

  return ans;
}

void reset() {
  mp = {};
  visited = {};
  fill(a, a + n + 1, 0);
  return;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    printf("%lld\n", solve());
    reset();
  }

  return 0;
}
