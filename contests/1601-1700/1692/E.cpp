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

int n, s, a[int(2e5 + 5)];
int sum[int(2e5 + 5)];

int solve() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  if (s > sum[n]) {
    return -1;
  }

  int ans = n, r = 1;
  for (int l = 1; l <= n; l++) {
    if (sum[n] - sum[l - 1] < s) {
      break;
    }
    if (sum[n] - sum[l - 1] == s) {
      ans = min(ans, l - 1);
      continue;
    }

    int ok = l, ng = n;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      if (sum[mid] - sum[l - 1] <= s) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    ans = min(ans, (l - 1) + (n - ok));
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
