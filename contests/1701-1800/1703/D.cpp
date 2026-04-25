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
string s[int(1e5 + 5)];
bool ans[int(1e5 + 5)];

void solve() {
  cin >> n;
  fill(ans + 1, ans + n + 1, false);

  map<ll, bool> visited;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    ll val = 0;
    for (int j = 0; j < s[i].length(); j++) {
      val *= 30;
      val += s[i][j] - 'a' + 1;
    }
    visited[val] = true;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i].length(); j++) {
      ll val1 = 0, val2 = 0;
      for (int k = 0; k < j; k++) {
        val1 *= 30;
        val1 += s[i][k] - 'a' + 1;
      }
      for (int k = j; k < s[i].length(); k++) {
        val2 *= 30;
        val2 += s[i][k] - 'a' + 1;
      }

      if (visited[val1] && visited[val2]) {
        ans[i] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';

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
