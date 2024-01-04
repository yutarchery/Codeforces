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

struct SegmentTree {
  int n;
  vector<ll> node;

  void init() {
    int res = 1;
    while (res < n) {
      res *= 2;
    }
    n = res;
    node.resize(2 * n - 1);
    return;
  }

  void insert(int idx, ll val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[idx * 2 + 1] + node[idx * 2 + 2];
    }
    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return get_sum(a, b, k * 2 + 1, l, (l + r) / 2) +
           get_sum(a, b, k * 2 + 2, (l + r) / 2, r);
  }
};

int n;
int a[int(2e5 + 5)], b[int(2e5 + 5)];
Pii p[int(2e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    p[i] = {a[i], b[i]};
  }

  map<int, int> idx;
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    idx[b[i]] = i;
  }

  SegmentTree tree;
  tree.n = n + 1;
  tree.init();

  sort(p + 1, p + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += tree.get_sum(idx[p[i].second] + 1, n + 1);
    tree.insert(idx[p[i].second], 1);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}
