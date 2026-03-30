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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m;
vector<int> a[int(3e5 + 5)], sum[int(3e5 + 5)];

void solve() {
  cin >> n >> m;

  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    a[i].resize(m + 2, 0);
    sum[i].resize(m + 2, 0);

    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum[i][j] = sum[i][j - 1] + a[i][j];
      cnt += a[i][j];
    }
  }

  cout << (cnt / 2) * ((cnt + 1) / 2) << '\n';

  string ans = "";
  int j = m;
  ll rest = cnt / 2;
  for (int i = n; i >= 1; i--) {
    if (rest >= sum[i][j]) {
      ans += 'D';
      rest -= sum[i][j];
      continue;
    }

    while (rest < sum[i][j]) {
      ans += 'R';
      j--;
    }
    rest -= sum[i][j];
    ans += 'D';
  }

  while (j > 0) {
    j--;
    ans += 'R';
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
