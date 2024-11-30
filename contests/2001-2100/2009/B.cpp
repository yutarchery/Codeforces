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

int t, n, ans[505];
char c[505][5];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", c[i] + 1);
      for (int j = 1; j <= 4; j++) {
        if (c[i][j] == '#') {
          ans[i] = j;
        }
      }
    }

    printf("%d", ans[n]);
    for (int i = n - 1; i >= 1; i--) {
      printf(" %d", ans[i]);
    }
    printf("\n");
  }

  return 0;
}
