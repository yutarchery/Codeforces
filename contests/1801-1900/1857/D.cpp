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

int t, n;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
Pli p[int(2e5 + 5)];

int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) {
      scanf("%lld", a + j);
    }
    for (int j = 1; j <= n; j++) {
      scanf("%lld", b + j);
    }

    for (int j = 1; j <= n; j++) {
      p[j] = {a[j] - b[j], j};
    }
    sort(p + 1, p + n + 1, greater<Pli>());

    int cnt = 0;
    vector<int> ans;
    for (int j = 1; j <= n; j++) {
      if (p[j].first == p[1].first) {
        cnt++;
        ans.push_back(p[j].second);
      } else {
        break;
      }
    }
    sort(ans.begin(), ans.end());

    printf("%d\n", cnt);
    printf("%d", ans[0]);
    for (int j = 1; j < cnt; j++) {
      printf(" %d", ans[j]);
    }
    printf("\n");
  }

  return 0;
}