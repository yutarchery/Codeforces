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

int n, a[int(2e5 + 5)];
int cnt[int(2e5 + 5)];

void solve() {
  cin >> n;
  fill(cnt + 1, cnt + n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] >= 2) {
      v.emplace_back(i);
    }
  }

  if (v.size() == 0) {
    cout << 1 << ' ' << n << '\n';
    return;
  }

  if (v.size() == n) {
    cout << 0 << '\n';
    return;
  }

  v.emplace_back(n + 1);
  int longest = v[0] - 1;
  int ans_l = 1, ans_r = v[0] - 1;

  for (int i = 0; i + 1 < v.size(); i++) {
    if ((v[i + 1] - 1) - v[i] > longest) {
      longest = (v[i + 1] - 1) - v[i];
      ans_l = v[i] + 1;
      ans_r = v[i + 1] - 1;
    }
  }

  cout << ans_l << ' ' << ans_r << '\n';

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
