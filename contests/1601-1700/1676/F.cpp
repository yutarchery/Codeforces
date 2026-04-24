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

int n, k, a[int(2e5 + 5)];

void solve() {
  cin >> n >> k;
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a + 1, a + n + 1);

  map<int, bool> visited;
  int ans_l = 0, ans_r = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[a[i]]) {
      continue;
    }
    if (cnt[a[i]] < k) {
      continue;
    }

    int now = 0, idx = a[i];
    while (cnt[idx] >= k) {
      visited[idx] = true;
      now++;
      idx++;
    }

    if (ans_r - ans_l < now) {
      ans_l = a[i];
      ans_r = a[i] + now - 1;
    }
  }

  if (ans_l == 0 && ans_r == 0) {
    cout << -1 << '\n';
  } else {
    cout << ans_l << ' ' << ans_r << '\n';
  }

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
