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

int n, m, r[int(2e6 + 5)], cnt = 0;
int pl[int(2e6 + 5)], mn[int(2e6 + 5)], dp[5005][5005];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &r[i]);
  }

  for (int i = 1; i <= n + 1; i++) {
    if (r[i] > 0) {
      if (r[i] <= cnt) {
        pl[r[i]]++;
      }
      continue;
    } else if (r[i] < 0) {
      if (-1 * r[i] <= cnt) {
        mn[-1 * r[i]]++;
      }
      continue;
    }

    for (int j = 1; j <= cnt; j++) {
      pl[j] += pl[j - 1];
      mn[j] += mn[j - 1];
    }

    for (int j = 0; j <= cnt; j++) {
      dp[j][cnt - j] += pl[j];
      dp[cnt - j][j] += mn[j];
    }
    fill(pl, pl + cnt + 1, 0);
    fill(mn, mn + cnt + 1, 0);

    cnt++;
    dp[cnt][0] = dp[cnt - 1][0];
    dp[0][cnt] = dp[0][cnt - 1];
    for (int j = 1; j <= cnt - 1; j++) {
      dp[j][cnt - j] = max(dp[j - 1][cnt - j], dp[j][cnt - j - 1]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= cnt; i++) {
    ans = max(ans, dp[i][cnt - i]);
  }
  cout << ans << endl;

  return 0;
}
