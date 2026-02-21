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

int n, k;
char s[int(1e6 + 5)];

int nexts[int(1e6 + 5)][26];
int dp[int(1e6 + 5)];

int q;
string t[int(2e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i];
  }

  fill(nexts[n], nexts[n] + k, -1);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < k; j++) {
      nexts[i][j] = nexts[i + 1][j];
    }
    nexts[i][s[i + 1] - 'a'] = i + 1;
  }

  for (int i = n; i >= 0; i--) {
    bool flag = false;
    for (int j = 0; j < k; j++) {
      if (nexts[i][j] == -1) {
        flag = true;
      }
    }

    if (flag) {
      dp[i] = 1;
      continue;
    }
    dp[i] = 1e9;
    for (int j = 0; j < k; j++) {
      dp[i] = min(dp[i], dp[nexts[i][j]] + 1);
    }
  }

  for (int i = 1; i <= q; i++) {
    int now = 0;
    for (int j = 0; j < t[i].length(); j++) {
      now = nexts[now][t[i][j] - 'a'];

      if (now == -1) {
        break;
      }
    }

    if (now == -1) {
      cout << 0 << endl;
    } else {
      cout << dp[now] << endl;
    }
  }

  return 0;
}
