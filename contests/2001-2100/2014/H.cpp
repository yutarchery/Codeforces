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

ll hash_value[int(1e6 + 5)];

int t, n, q, a[int(2e5 + 5)], l, r;
ll now[int(2e5 + 5)];
bool used[int(1e6 + 5)];

void solve() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!used[a[i]]) {
      now[i] = (now[i - 1] + hash_value[a[i]]) % MOD2;
    } else {
      now[i] = (now[i - 1] - hash_value[a[i]]) % MOD2;
      if (now[i] < 0) {
        now[i] += MOD2;
      }
    }
    used[a[i]] = !used[a[i]];
  }

  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &l, &r);
    if (now[r] == now[l - 1]) {
      YES();
    } else {
      NO();
    }
  }

  return;
}

void reset() {
  fill(now, now + n + 1, 0);
  fill(used, used + int(1e6 + 1), false);
  return;
}

int main() {
  hash_value[0] = 1;
  for (int i = 1; i <= int(1e6); i++) {
    hash_value[i] = hash_value[i - 1] * 2 % MOD2;
  }

  scanf("%d", &t);
  while (t--) {
    solve();
    reset();
  }

  return 0;
}
