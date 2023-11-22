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

int t, n;
string s;

void solve() {
  if (n <= 3) {
    NO();
    return;
  }

  bool used[26][26] = {};

  for (int i = 0; i + 1 < n; i++) {
    if (used[s[i] - 'a'][s[i + 1] - 'a']) {
      YES();
      return;
    }

    if (i - 1 >= 0) {
      used[s[i - 1] - 'a'][s[i] - 'a'] = true;
    }
  }
  NO();
  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cin >> s;
    solve();
  }

  return 0;
}