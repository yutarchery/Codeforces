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
ll k, q[int(2e5 + 5)], r[int(2e5 + 5)];

ll solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }
  sort(q + 1, q + n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  sort(r + 1, r + n + 1);

  int ans = 0, r_idx = n;
  for (int i = 1; i <= n; i++) {
    bool flag = false;
    for (int j = r_idx; j >= 1; j--) {
      if (r[j] <= (k + 1) / (q[i] + 1) - 1) {
        flag = true;
        r_idx = j - 1;
        ans++;
        break;
      }
    }
    if (!flag) {
      break;
    }
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
    cout << solve() << endl;
  }

  return 0;
}
