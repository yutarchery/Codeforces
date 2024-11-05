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

int n, k, a[int(2e5 + 5)];

int solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 1);

  if (n == 1) {
    return 1;
  }

  int l = 1, r = 1, ans = 0;
  while (r < n) {
    while (a[r + 1] - a[l] <= k - 1 && r + 1 <= n && a[r + 1] - a[r] <= 1) {
      r++;
    }
    ans = max(ans, r - l + 1);

    int now = a[l];
    while (now == a[l] && l + 1 <= n) {
      l++;
    }
    if (l > r) {
      r = l;
    }
  }

  return ans;
}

void reset() {
  fill(a, a + n + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
