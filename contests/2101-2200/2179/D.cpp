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
vector<int> vals[20];

void solve() {
  cin >> n;

  for (int i = 0; i <= n; i++) {
    vals[i].resize(0);
  }

  for (int i = 0; i <= (1 << n) - 1; i++) {
    int rest = i, cnt = 0;
    while (rest % 2 == 1) {
      cnt++;
      rest /= 2;
    }
    vals[cnt].emplace_back(i);
  }

  vector<int> ans;
  for (int i = n; i >= 0; i--) {
    for (int j : vals[i]) {
      ans.emplace_back(j);
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    cout << ans[i] << (i == (1 << n) - 1 ? '\n' : ' ');
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
