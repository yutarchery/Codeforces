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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
ll a[int(1e5 + 5)];
ll pows[int(1e5 + 5)];

ll solve() {
  cin >> n;
  fill(pows + 1, pows + n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    if (a[i - 1] > a[i]) {
      ll now = a[i];
      while (now < a[i - 1]) {
        now *= 2;
        pows[i]++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    pows[i] += pows[i - 1];

    if (a[i - 1] <= a[i]) {
      ll now = a[i - 1];
      while (pows[i] > 0) {
        if (now * 2 > a[i]) {
          break;
        } else {
          now *= 2;
          pows[i]--;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += pows[i];
  }
  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
