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

int t, a[2], b[2];

int main() {
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 2; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + 2);
    for (int i = 0; i < 2; i++) {
      scanf("%d", &b[i]);
    }
    sort(b, b + 2);

    int ans = 0;
    if (a[0] >= b[0] && a[1] >= b[1] && !(a[0] == b[0] && a[1] == b[1])) {
      ans += 2;
    }
    swap(b[0], b[1]);
    if (a[0] >= b[0] && a[1] >= b[1] && !(a[0] == b[0] && a[1] == b[1])) {
      ans += 2;
    }

    printf("%d\n", ans);
  }

  return 0;
}
