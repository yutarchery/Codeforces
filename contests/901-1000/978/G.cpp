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

int n, m, s[105], d[105], c[105];
int ans[105];

vector<array<int, 3>> d_c_idx[105];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s[i] >> d[i] >> c[i];
    ans[d[i]] = m + 1;
    d_c_idx[s[i]].push_back({d[i], c[i], i});
  }

  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
      que;
  for (int i = 1; i <= n; i++) {
    for (array<int, 3> a : d_c_idx[i]) {
      que.push(a);
    }
    if (ans[i] == m + 1) {
      continue;
    }

    if (que.empty()) {
      ans[i] = 0;
    } else {
      array<int, 3> q = que.top();
      que.pop();

      if (i <= q[0] - 1) {
        ans[i] = q[2];
        q[1]--;
        if (q[1] > 0) {
          que.push(q);
        }
      } else {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  if (!que.empty()) {
    cout << -1 << '\n';
  } else {
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << (i == n ? '\n' : ' ');
    }
  }

  return 0;
}
