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
ll m, a[int(1e5 + 5)], b[int(1e5 + 5)];
ll sum = 0;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;

  priority_queue<ll> que;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sum += a[i];
    que.push(a[i] - b[i]);
  }

  int ans = 0;
  while (!que.empty()) {
    if (sum <= m) {
      break;
    }

    ll q = que.top();
    que.pop();
    ans++;
    sum -= q;
  }

  if (sum <= m) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
