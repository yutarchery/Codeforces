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
ll x, y, d;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld %lld", &x, &y, &d);
    ll ans_x = x / d, ans_y = y / d;
    if (x % d != 0) {
      ans_x++;
    }
    if (y % d != 0) {
      ans_y++;
    }

    if (ans_x > ans_y) {
      printf("%lld\n", ans_x * 2 - 1);
    } else {
      printf("%lld\n", ans_y * 2);
    }
  }

  return 0;
}
