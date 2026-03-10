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

ll pows[31];

int l, r;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
ll cnt[31];

void solve() {
  cin >> l >> r;
  fill(b + l, b + r + 1, 0);

  for (int i = l; i <= r; i++) {
    a[i] = i;

    int rest = i;
    for (int j = 0; j <= 30; j++) {
      if (rest % 2 == 1) {
        cnt[j]++;
      }
      rest /= 2;
    }
  }

  for (int i = r; i >= l; i--) {
    for (int j = 0; j <= 30; j++) {
      if (cnt[j] == 0) {
        continue;
      }

      if ((a[i] & pows[j]) == 0) {
        b[i] += pows[j];
        cnt[j]--;
      }
    }
  }

  ll ans = 0;
  for (int i = l; i <= r; i++) {
    ans += (a[i] | b[i]);
  }

  cout << ans << endl;
  for (int i = l; i <= r; i++) {
    cout << b[i] << (i == r ? '\n' : ' ');
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  pows[0] = 1;
  for (int i = 1; i <= 30; i++) {
    pows[i] = pows[i - 1] * 2;
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
