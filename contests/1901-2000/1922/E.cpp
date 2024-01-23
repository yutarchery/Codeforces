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

ll x;
bool bit[105];
int p[105], q[105];

void solve() {
  cin >> x;

  int m = 0;
  for (int i = 0; i <= 100; i++) {
    bit[i] = x % 2;
    x /= 2;

    if (bit[i]) {
      m = i;
    }
  }

  for (int i = 1; i <= m; i++) {
    p[i] = i;
  }
  int now = m + 1;
  for (int i = m - 1; i >= 0; i--) {
    if (bit[i]) {
      q[i] = now;
      now++;
    }
  }

  vector<int> ans;
  for (int i = 0; i <= m; i++) {
    if (p[i] > 0) {
      ans.push_back(p[i]);
    }
    if (q[i] > 0) {
      ans.push_back(q[i]);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

void reset() {
  fill(bit, bit + 101, false);
  fill(p, p + 101, 0);
  fill(q, q + 101, 0);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    reset();
    solve();
  }

  return 0;
}
