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

int t, n, x[int(2e5 + 5)], y[int(2e5 + 5)];
bool used[int(2e5 + 5)][2];

ll solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    used[x[i]][y[i]] = true;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (y[i] == 0 && used[x[i]][1]) {
      ans += n - 2;
    }

    if (x[i] >= 1 && used[x[i] - 1][1 - y[i]] && used[x[i] + 1][1 - y[i]]) {
      ans++;
    }
  }

  return ans;
}

void reset() {
  fill((bool *)used, (bool *)(used + n + 1), false);
  return;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", solve());
    reset();
  }

  return 0;
}
