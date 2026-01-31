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

ll a, b;
bool bits_a[60], bits_b[60];

void solve() {
  cin >> a >> b;
  for (int i = 0; i < 60; i++) {
    bits_a[i] = (a % 2 == 1);
    a /= 2;

    bits_b[i] = (b % 2 == 1);
    b /= 2;
  }

  for (int i = 59; i >= 0; i--) {
    if (bits_a[i]) {
      break;
    } else if (bits_b[i]) {
      cout << -1 << endl;
      return;
    }
  }

  vector<ll> ans;
  for (int i = 0; i < 60; i++) {
    if (bits_a[i] != bits_b[i]) {
      ans.push_back((1ll) << i);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

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
