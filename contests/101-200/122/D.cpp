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
ll k;
string d;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  cin >> d;

  if (k == 0) {
    cout << d << '\n';
    return 0;
  }

  string before = "", now = d;
  int cnt = 0;
  bool is_same = false;
  for (int i = 0; i + 1 < n; i++) {
    if (d[i] == '4' && d[i + 1] == '7') {
      if (i % 2 == 0) {
        d[i + 1] = '4';
      } else {
        d[i] = '7';
      }

      if (before == d) {
        is_same = true;
        break;
      }

      cnt++;
      before = now;
      now = d;
      i = max(-1, i - 3);
    }

    if (cnt == k) {
      cout << now << '\n';
      return 0;
    }
  }

  if (is_same) {
    if (k % 2 == cnt % 2) {
      cout << now << '\n';
    } else {
      cout << before << '\n';
    }
  } else {
    cout << now << '\n';
  }

  return 0;
}
