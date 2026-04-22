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
char s[int(1e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  int cnt = 0;
  bool flag_b = false, flag_r = false;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'W') {
      if (cnt > 0) {
        if (!flag_b || !flag_r) {
          NO();
          return;
        }
      }
      cnt = 0;
      flag_b = false;
      flag_r = false;
    } else if (s[i] == 'B') {
      cnt++;
      flag_b = true;
    } else {
      cnt++;
      flag_r = true;
    }
  }

  if (cnt > 0) {
    if (!flag_b || !flag_r) {
      NO();
      return;
    }
  }

  YES();
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
