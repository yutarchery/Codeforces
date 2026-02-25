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

ll solve(ll a, ll b) {
  int ans = 0, turn = 0;
  ll now = 1;

  while (true) {
    if (turn == 0) {
      if (a >= now) {
        a -= now;
        now *= 2;
        ans++;
      } else {
        return ans;
      }
    } else {
      if (b >= now) {
        b -= now;
        now *= 2;
        ans++;
      } else {
        return ans;
      }
    }

    turn = 1 - turn;
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << max(solve(a, b), solve(b, a)) << endl;
  }

  return 0;
}
