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

int n;
ll w[int(2e5 + 5)];
ll sum_l[int(2e5 + 5)], sum_r[int(2e5 + 5)];

int solve() {
  cin >> n;
  fill(sum_l, sum_l + n + 2, 0);
  fill(sum_r, sum_r + n + 2, 0);

  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }

  map<ll, int> mp;
  for (int i = 1; i <= n; i++) {
    sum_l[i] = sum_l[i - 1] + w[i];
    mp[sum_l[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    sum_r[i] = sum_r[i + 1] + w[i];
  }

  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (mp[sum_r[i]] > 0 && mp[sum_r[i]] < i) {
      ans = max(ans, (n - i + 1) + mp[sum_r[i]]);
    }
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
