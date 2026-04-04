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

int n, q;
string s[int(2e5 + 5)];
const string c[6] = {"BG", "BR", "BY", "GR", "GY", "RY"};

ll ans[int(2e5 + 5)];

bool has_same(string si, string sj) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (si[i] == sj[j]) {
        return true;
      }
    }
  }

  return false;
}

void solve() {
  set<ll> st[6];
  for (int i = 0; i < 6; i++) {
    st[i].insert(-1e16);
    st[i].insert(1e16);
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 0; j < 6; j++) {
      if (s[i] == c[j]) {
        st[j].insert(i);
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }

    if (has_same(s[u], s[v])) {
      ans[i] = abs(u - v);
      continue;
    }

    ans[i] = 1e9;
    for (int j = 0; j < 6; j++) {
      if (c[j] == s[u] || c[j] == s[v]) {
        continue;
      }

      auto iter = st[j].upper_bound(u);
      ans[i] = min(ans[i], abs(u - *iter) + abs(*iter - v));

      iter--;
      ans[i] = min(ans[i], abs(u - *iter) + abs(*iter - v));
    }

    if (ans[i] == 1e9) {
      ans[i] = -1;
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
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
