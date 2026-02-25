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

string solve() {
  int n0, n1, n2;
  cin >> n0 >> n1 >> n2;

  string ans = "";
  if (n0 == 0 && n2 == 0) {
    n1--;
    ans += "01";
    while (n1 >= 2) {
      ans += "01";
      n1 -= 2;
    }
    if (n1 == 1) {
      ans += "0";
    }

    return ans;
  }

  string zeros = "0", ones = "1";
  for (int i = 1; i <= n0; i++) {
    zeros += "0";
  }
  for (int i = 1; i <= n2; i++) {
    ones += "1";
  }

  if (n2 == 0) {
    while (n1 >= 2) {
      zeros += "10";
      n1 -= 2;
    }
    if (n1 == 1) {
      zeros += "1";
    }
    return zeros;
  }
  if (n0 == 0) {
    while (n1 >= 2) {
      ones += "01";
      n1 -= 2;
    }
    if (n1 == 1) {
      ones += "0";
    }
    return ones;
  }

  ans = zeros + ones;
  n1--;
  while (n1 >= 2) {
    ans += "01";
    n1 -= 2;
  }
  if (n1 == 1) {
    ans += "0";
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
