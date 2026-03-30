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

int n, k;
vector<char> s[int(5e4 + 5)];

bool judge(int length, int idx, char c) {
  for (int j = idx; j <= n; j += length) {
    bool flag = false;
    for (int i = 1; i <= k; i++) {
      if (s[i][j] == c) {
        flag = true;
      }
    }

    if (!flag) {
      return false;
    }
  }

  return true;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    s[i].resize(n + 1);
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (n % i != 0) {
      continue;
    }

    string ans = "";
    bool is_valid = true;
    for (int j = 1; j <= i; j++) {
      bool now = false;
      for (char c = 'a'; c <= 'z'; c++) {
        if (judge(i, j, c)) {
          ans += c;
          now = true;
          break;
        }
      }

      if (!now) {
        is_valid = false;
        break;
      }
    }

    if (is_valid) {
      for (int j = 0; j < n / i; j++) {
        cout << ans;
      }
      cout << '\n';
      return;
    } else {
      continue;
    }
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
