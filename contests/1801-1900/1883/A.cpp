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

char c[4];

int solve() {
  for (int i = 0; i < 4; i++) {
    cin >> c[i];
  }

  int ans = 0;
  char now = '1';
  for (int i = 0; i < 4; i++) {
    if (now == c[i]) {
      ans++;
    } else if (now == '0') {
      ans += abs(10 - (c[i] - '0')) + 1;
    } else if (c[i] == '0') {
      ans += abs(10 - (now - '0')) + 1;
    } else {
      ans += abs(now - c[i]) + 1;
    }

    now = c[i];
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
