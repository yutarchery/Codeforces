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

int t, n, m;
string s;

int solve() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      ans++;
      for (int j = 0; j < m && i + j < n; j++) {
        s[i + j] = 'W';
      }
    }
  }
  return ans;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    cin >> s;
    cout << solve() << endl;
  }

  return 0;
}