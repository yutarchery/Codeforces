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

void solve() {
  ll n;
  cin >> n;
  int l = 1, r = n;

  ll sum_p, sum_a;
  cout << "2 " << l << " " << r << endl;
  cin >> sum_a;
  ll diff = sum_a - n * (n + 1) / 2;

  while (r - l > diff - 1) {
    int mid = (l + r) / 2;

    cout << "1 " << l << " " << mid << endl;
    cin >> sum_p;
    cout << "2 " << l << " " << mid << endl;
    cin >> sum_a;

    if (sum_a - sum_p == diff) {
      r = mid;
      continue;
    } else if (sum_p == sum_a) {
      l = mid + 1;
      continue;
    } else {
      l = mid - ((sum_a - sum_p) - 1);
      r = mid + (diff - (sum_a - sum_p));
    }
  }
  cout << "! " << l << " " << r << endl;

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
