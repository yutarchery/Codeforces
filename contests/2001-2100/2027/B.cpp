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
  vector<int> node;

  void init(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1);
    return;
  }

  void add(int idx, int val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[idx * 2 + 1] + node[idx * 2 + 2];
    }
    return;
  }

  int get_sum(int a, int b, int l = 0, int r = -1, int k = 0) {
    if (r == -1) {
      r = n;
    }

    if (b <= l || r <= a) {
      return 0;
    }

    if (a <= l && r <= b) {
      return node[k];
    }

    return get_sum(a, b, l, (l + r) / 2, k * 2 + 1) +
           get_sum(a, b, (l + r) / 2, r, k * 2 + 2);
  }
};

int n, a[2005];

int solve() {
  scanf("%d", &n);
  set<int> st;
  map<int, int> idx;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    st.insert(a[i]);
  }

  SegmentTree tree;
  tree.init(n + 5);
  int cnt = 0;
  for (int s : st) {
    cnt++;
    idx[s] = cnt;
  }

  int ans = n;
  for (int i = n; i >= 1; i--) {
    ans = min(ans, i - 1 + tree.get_sum(idx[a[i]] + 1, n + 2));
    tree.add(idx[a[i]], 1);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", solve());
  }

  return 0;
}
