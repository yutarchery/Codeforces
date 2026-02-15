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
ll ax, ay, bx, by;
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

set<ll> set_x;
map<ll, int> x_idx;
vector<ll> xs;
ll y_min[int(2e5 + 5)], y_max[int(2e5 + 5)];

ll dp_min[int(2e5 + 5)], dp_max[int(2e5 + 5)];

void prepare() {
  cin >> n >> ax >> ay >> bx >> by;

  set_x = {};
  x_idx = {};
  xs.resize(0);

  fill(y_min, y_min + n + 1, ll(1e16));
  fill(y_max, y_max + n + 1, 0);

  fill(dp_min + 1, dp_min + n + 2, ll(1e16));
  fill(dp_max + 1, dp_max + n + 2, ll(1e16));

  set_x.insert(ax);
  set_x.insert(bx);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    set_x.insert(x[i]);
  }

  for (ll now_x : set_x) {
    x_idx[now_x] = xs.size();
    xs.push_back(now_x);
  }

  y_min[0] = ay;
  y_max[0] = ay;
  for (int i = 1; i <= n; i++) {
    cin >> y[i];

    int idx = x_idx[x[i]];
    y_min[idx] = min(y_min[idx], y[i]);
    y_max[idx] = max(y_max[idx], y[i]);
  }
  y_min[x_idx[bx]] = by;
  y_max[x_idx[bx]] = by;

  return;
}

ll solve() {
  prepare();

  for (int i = 1; i < xs.size(); i++) {
    dp_min[i] = min(dp_min[i - 1] + abs(y_min[i - 1] - y_max[i]) +
                        abs(y_max[i] - y_min[i]),
                    dp_max[i - 1] + abs(y_max[i - 1] - y_max[i]) +
                        abs(y_max[i] - y_min[i]));

    dp_max[i] = min(dp_min[i - 1] + abs(y_min[i - 1] - y_min[i]) +
                        abs(y_max[i] - y_min[i]),
                    dp_max[i - 1] + abs(y_max[i - 1] - y_min[i]) +
                        abs(y_max[i] - y_min[i]));
  }

  return min(dp_min[xs.size() - 1], dp_max[xs.size() - 1]) +
         (xs[xs.size() - 1] - xs[0]);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
