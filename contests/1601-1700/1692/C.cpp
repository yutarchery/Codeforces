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

char s[10][10];

void solve() {
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> s[i][j];
    }
  }

  bool flag2 = false;
  for (int i = 1; i <= 8; i++) {
    int cnt = 0, now_j = 0;
    for (int j = 1; j <= 8; j++) {
      if (s[i][j] == '#') {
        cnt++;
        now_j = j;
      }
    }

    if (cnt == 2 && !flag2) {
      flag2 = true;
    } else if (cnt == 1 && flag2) {
      cout << i << " " << now_j << '\n';
      return;
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
