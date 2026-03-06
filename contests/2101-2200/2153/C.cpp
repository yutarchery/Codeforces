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
ll a[int(2e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  a[n + 1] = 0;

  ll ans = 0;
  vector<ll> rest;
  int cnt = 1, used = 0;
  for (int i = 2; i <= n + 1; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      ans += a[i - 1] * (cnt / 2) * 2;
      if (cnt % 2 == 1) {
        rest.emplace_back(a[i - 1]);
      }
      used += (cnt / 2) * 2;
      cnt = 1;
    }
  }

  rest.emplace_back(0);
  sort(rest.begin(), rest.end());

  ll extra = 0;
  for (int i = 0; i + 1 < rest.size(); i++) {
    if (rest[i] + ans <= rest[i + 1]) {
      continue;
    }
    if (rest[i] + ans > rest[rest.size() - 1]) {
      extra = max(extra, rest[i] + rest[rest.size() - 1]);
      continue;
    }

    int ok = i + 1, ng = rest.size() - 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      if (rest[i] + ans > rest[mid]) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    extra = max(extra, rest[i] + rest[ok]);
  }

  if (used == 0) {
    return 0;
  } else if (used == 2 && extra == 0) {
    return 0;
  } else {
    return ans + extra;
  }
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
