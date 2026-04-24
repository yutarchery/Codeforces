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

char s[5], now[5];
int x;

bool judge(int h, int w) {
  int trans_h = 0;
  for (int _ = 0; _ < 2; _++) {
    trans_h *= 10;
    trans_h += h % 10;
    h /= 10;
  }

  return trans_h == w;
}

int solve() {
  for (int i = 0; i < 5; i++) {
    cin >> s[i];
    now[i] = s[i];
  }
  int h = (s[0] - '0') * 10 + (s[1] - '0');
  int w = (s[3] - '0') * 10 + (s[4] - '0');

  cin >> x;

  bool visited[24][60] = {};
  int ans = 0;
  while (!visited[h][w]) {
    visited[h][w] = true;
    if (judge(h, w)) {
      ans++;
    }

    w += x;
    while (w >= 60) {
      h++;
      w -= 60;

      while (h >= 24) {
        h -= 24;
      }
    }
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
