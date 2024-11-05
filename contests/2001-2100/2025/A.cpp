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

int q;
string s, t;

int solve() {
  cin >> s >> t;

  int ans = s.length() + t.length();
  bool flag = false;
  for (int i = 0; i < min(s.length(), t.length()); i++) {
    if (s[i] != t[i]) {
      break;
    } else {
      flag = true;
      ans--;
    }
  }
  if (flag) {
    ans++;
  }
  return ans;
}

int main() {
  cin >> q;
  while (q--) {
    cout << solve() << endl;
  }

  return 0;
}
