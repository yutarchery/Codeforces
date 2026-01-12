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

int n;
char s[25], t[25];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  sort(t + 1, t + n + 1);

  for (int i = 1; i <= n; i++) {
    if (s[i] != t[i]) {
      NO();
      return;
    }
  }

  YES();
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
