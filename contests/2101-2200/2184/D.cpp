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

ll pows[31];
ll dp[31][105][2];

bool now[31];

ll solve() {
  int n, k;
  cin >> n >> k;

  int rest = n;
  for (int i = 30; i >= 0; i--) {
    now[i] = (rest % 2 == 1);
    rest /= 2;
  }

  bool is_first = true;
  for (int i = 0; i <= 30; i++) {
    if (is_first && now[i]) {
      dp[i][1][1] = 1;
      is_first = false;
    } else if (!is_first) {
      dp[i][1][0] = 1;
    }
  }

  for (int i = 1; i <= 30; i++) {
    for (int j = 0; j <= 100; j++) {
      if (now[i]) {
        dp[i][j + 2][1] += dp[i - 1][j][1];
        dp[i][j + 1][0] += dp[i - 1][j][1];
      } else {
        dp[i][j + 1][1] += dp[i - 1][j][1];
      }

      dp[i][j + 2][0] += dp[i - 1][j][0];
      dp[i][j + 1][0] += dp[i - 1][j][0];
    }
  }

  ll ans = 0;
  for (int j = k + 1; j <= 100; j++) {
    ans += dp[30][j][0] + dp[30][j][1];
  }

  return ans;
}

void reset() {
  for (int i = 0; i <= 30; i++) {
    for (int j = 0; j <= 100; j++) {
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  pows[30] = 1;
  for (int i = 29; i >= 0; i--) {
    pows[i] = pows[i + 1] * 2;
  }

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
