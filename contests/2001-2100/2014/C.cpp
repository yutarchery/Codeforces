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

int t;
ll n, a[int(2e5 + 5)];

ll solve() {
  ll sum = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  sort(a + 1, a + n + 1);

  if (n <= 2) {
    return -1;
  }

  ll l = -1, r = 1e14;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    a[n] += mid;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] * n * 2 < sum + mid) {
        cnt++;
      }
    }
    a[n] -= mid;

    if (cnt * 2 > n) {
      r = mid;
    } else {
      l = mid;
    }
  }

  return r;
}

void reset() {
  fill(a + 1, a + n + 1, 0);
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
