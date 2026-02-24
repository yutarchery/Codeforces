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
ll a[105];

vector<ll> vals[105], ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    ll cnt = 0, rest = a[i];
    while (rest % 3 == 0) {
      rest /= 3;
      cnt++;
    }
    vals[cnt].push_back(a[i]);
  }

  for (int i = 100; i >= 0; i--) {
    if (vals[i].empty()) {
      continue;
    }

    sort(vals[i].begin(), vals[i].end());
    for (ll v : vals[i]) {
      ans.push_back(v);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
