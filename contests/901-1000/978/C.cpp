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

int n, m;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
ll sum_a[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum_a[i] = sum_a[i - 1] + a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= m; i++) {
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;

      if (sum_a[mid] < b[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }

    cout << l + 1 << " " << b[i] - sum_a[l] << endl;
  }

  return 0;
}
