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

int la, ra, lb, rb;
int cnt[105];

int solve() {
  fill(cnt, cnt + 101, 0);
  cin >> la >> ra;
  cin >> lb >> rb;

  for (int i = la; i <= ra; i++) {
    cnt[i]++;
  }
  for (int i = lb; i <= rb; i++) {
    cnt[i]++;
  }

  int ans = 0;
  for (int i = 1; i <= 99; i++) {
    if (cnt[i] == 0 || cnt[i + 1] == 0) {
      continue;
    }
    if (cnt[i] <= 1 && cnt[i + 1] <= 1) {
      continue;
    }

    ans++;
  }

  return max(ans, 1);
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
