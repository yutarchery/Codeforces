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

ll val[4];
bool bit[65][4];

ll solve() {
  for (int j = 1; j <= 3; j++) {
    scanf("%lld", &val[j]);
  }
  for (int i = 0; i < 65; i++) {
    for (int j = 1; j <= 3; j++) {
      if (val[j] % 2 == 1) {
        bit[i][j] = true;
      }
      val[j] /= 2;
    }
  }

  for (int i = 0; i < 65; i++) {
    if (((true | bit[i][1]) ^ (true & bit[i][2])) == bit[i][3]) {
      bit[i][0] = true;
    } else if (((false | bit[i][1]) ^ (false & bit[i][2])) == bit[i][3]) {
      bit[i][0] = false;
    } else {
      return -1;
    }
  }

  ll ans = 0;
  for (ll i = 0; i < 65; i++) {
    if (bit[i][0]) {
      ans += (1ll << i);
    }
  }
  return ans;
}

void reset() {
  for (int i = 0; i < 65; i++) {
    for (int j = 0; j < 4; j++) {
      bit[i][j] = false;
    }
  }
  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    printf("%lld\n", solve());
    reset();
  }

  return 0;
}
