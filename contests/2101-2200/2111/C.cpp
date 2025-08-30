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

ll n, a[int(5e5 + 5)];

ll solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<Pll> p;
  ll cnt = 1, now = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] == now) {
      cnt++;
    } else {
      p.push_back({now, cnt});
      now = a[i];
      cnt = 1;
    }
  }
  p.push_back({now, cnt});

  ll ans = 1e16;
  for (int i = 0; i < p.size(); i++) {
    ans = min(ans, p[i].first * (n - p[i].second));
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
