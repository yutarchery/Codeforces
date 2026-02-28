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

int n, k, h[int(1e5 + 5)];
Pii p[int(1e5 + 5)];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    p[i] = {h[i], i};
  }
  sort(p + 1, p + n + 1);

  bool flag = false;
  int height = 0;
  for (int i = 1; i <= n; i++) {
    if (!flag) {
      if (p[i].second == k) {
        flag = true;
      }
    } else {
      if (height + p[i].first - p[i - 1].first <= p[i - 1].first) {
        height += p[i].first - p[i - 1].first;
      } else {
        NO();
        return;
      }
    }
  }

  YES();
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
