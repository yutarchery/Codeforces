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
ll a[int(2e5 + 5)];

ll solve() {
  cin >> n;
  vector<ll> odds, evens;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1) {
      odds.push_back(a[i]);
    } else {
      evens.push_back(a[i]);
    }
  }
  sort(odds.begin(), odds.end());
  sort(evens.begin(), evens.end());

  ll ans = 0;
  if (odds.size() == 0) {
    return 0;
  }

  ans += odds[odds.size() - 1];
  for (ll e : evens) {
    ans += e;
  }

  for (int i = odds.size() / 2; i < odds.size() - 1; i++) {
    ans += odds[i];
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
