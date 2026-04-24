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
ll a[int(2e5 + 5)], cnt[10];

void solve() {
  cin >> n;
  fill(cnt, cnt + 10, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i] % 10]++;
  }

  ll ans = 0;
  for (int i = 0; i <= 9; i++) {
    for (int j = i; j <= 9; j++) {
      for (int k = j; k <= 9; k++) {
        if ((i + j + k) % 10 != 3) {
          continue;
        }

        if (i == j && j == k) {
          ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        } else if (i == j) {
          ans += cnt[i] * (cnt[i] - 1) * cnt[k] / 2;
        } else if (j == k) {
          ans += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
        } else {
          ans += cnt[i] * cnt[j] * cnt[k];
        }
      }
    }
  }

  (ans > 0) ? YES() : NO();
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
