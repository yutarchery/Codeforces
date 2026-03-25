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

string s;
char c[int(3e5 + 5)];
int l[int(3e5 + 5)], r[int(3e5 + 5)];

int solve() {
  cin >> s;

  int n = s.length();
  for (int i = 1; i <= n; i++) {
    c[i] = s[i - 1];
  }

  fill(l, l + n + 2, 0);
  fill(r, r + n + 2, 0);

  for (int i = 1; i <= n; i++) {
    if (c[i] == '>' || c[i] == '*') {
      l[i] = l[i - 1] + 1;
    } else {
      if (l[i - 1] > 0) {
        return -1;
      } else {
        l[i] = 0;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    if (c[i] == '<' || c[i] == '*') {
      r[i] = r[i + 1] + 1;
    } else {
      if (r[i + 1] > 0) {
        return -1;
      } else {
        r[i] = 0;
      }
    }
  }

  for (int i = 1; i + 1 <= n; i++) {
    if (c[i] == '*' && c[i + 1] == '*') {
      return -1;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, l[i]);
    ans = max(ans, r[i]);
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
