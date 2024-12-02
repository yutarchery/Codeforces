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

int solve() {
  int n;
  scanf("%d", &n);
  int max_h = 0, max_w = 0, h, w;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &h, &w);
    max_h = max(max_h, h);
    max_w = max(max_w, w);
  }

  return (max_h + max_w) * 2;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    printf("%d\n", solve());
  }

  return 0;
}
