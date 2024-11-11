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
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll l = 1, r = 1000;
    while (r - l > 1) {
      ll m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;

      cout << "? " << m1 << " " << m2 << endl;
      ll s;
      cin >> s;

      if (m1 * m2 == s) {
        l = m2;
      } else if (m1 * (m2 + 1) == s) {
        l = m1;
        r = m2;
      } else {
        r = m1;
      }
    }
    cout << "! " << r << endl;
  }

  return 0;
}
