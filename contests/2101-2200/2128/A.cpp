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
ll c, a[35], l[35];

int solve() {
  cin >> n >> c;

  priority_queue<ll> que1, que2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    que1.push(a[i]);
  }

  l[1] = c;
  que2.push(l[1]);
  for (int i = 2; i <= n; i++) {
    l[i] = l[i - 1] / 2;
    que2.push(l[i]);
  }

  int ans = 0;
  while (!que1.empty()) {
    ll q1 = que1.top(), q2 = que2.top();

    que1.pop();

    if (q1 <= q2) {
      que2.pop();
    } else {
      ans++;
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
    cout << solve() << '\n';
  }

  return 0;
}
