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

int n, x_cnt[105], y_cnt[105];
ll a[int(2e5 + 5)];
map<ll, Pii> combi;

void prepare() {
  vector<ll> p;
  ll now = 1;
  while (now < ll(4e9)) {
    p.push_back(now);
    now *= 2;
  }

  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j < p.size(); j++) {
      combi[p[i] - p[j]] = {i, j};
    }
  }

  return;
}

bool solve() {
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum % n != 0) {
    return false;
  }

  for (int i = 1; i <= n; i++) {
    ll diff = a[i] - (sum / n);
    if (diff == 0) {
      continue;
    }

    if (combi[diff] == make_pair(0, 0)) {
      return false;
    }

    x_cnt[combi[diff].first]++;
    y_cnt[combi[diff].second]++;
  }

  for (int i = 0; i < 100; i++) {
    if (x_cnt[i] != y_cnt[i]) {
      return false;
    }
  }

  return true;
}

void reset() {
  fill(a, a + n + 1, 0);
  fill(x_cnt, x_cnt + 100, 0);
  fill(y_cnt, y_cnt + 100, 0);
  return;
}

int main() {
  prepare();

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (solve()) {
      Yes();
    } else {
      No();
    }
    reset();
  }

  return 0;
}