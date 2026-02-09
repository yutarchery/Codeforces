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

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, 0);
  }

  void add(int idx, int val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = max(node[2 * idx + 1], node[2 * idx + 2]);
    }
    return;
  }

  int get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }

    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, a[int(2e5 + 5)];
vector<int> primes[int(2e5 + 5)];

int ans[int(2e5 + 5)];

void prepare(int num) {
  for (int j = 1; j * j <= num; j++) {
    if (num % j == 0) {
      primes[num].push_back(j);
      if (j * j != num) {
        primes[num].push_back(num / j);
      }
    }
  }
  return;
}

int my_gcd(int a, int b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (primes[a[i]].size() == 0) {
      prepare(a[i]);
    }
  }
  fill(ans, ans + n + 1, 0);

  SegmentTree tree(n + 5);

  int g = a[1];
  int now_ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j : primes[a[i]]) {
      tree.add(j, 1);
    }
    g = my_gcd(g, a[i]);

    ans[i] = tree.get_max(g + 1, n + 1);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
