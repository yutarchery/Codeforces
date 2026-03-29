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
ll a[int(2e5 + 5)], sum[int(2e5 + 5)];
ll diff_r[int(2e5 + 5)], sum_r[int(2e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    diff_r[i] = 2 * i - a[i];
    sum_r[i] = sum_r[i - 1] + diff_r[i];
  }

  ll ans = sum[n];
  priority_queue<ll> que;

  for (int i = n; i >= 1; i--) {
    que.push(sum_r[i]);

    ll q = que.top();
    ans = max(ans, sum[n] + (q - sum_r[i - 1]));
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
