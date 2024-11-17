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

int n, k, q;
vector<int> a[int(1e5 + 5)];
int m, r[int(1e5 + 5)], c[int(1e5 + 5)];
char o[int(1e5 + 5)];

int max_search(int idx, int val) {
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (a[mid][idx] < val) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

int min_search(int idx, int val) {
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid][idx] <= val) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return r;
}

int solve() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %c %d", &r[i], &o[i], &c[i]);
  }

  int ans_min = 1, ans_max = n;
  for (int i = 1; i <= m; i++) {
    if (o[i] == '<') {
      ans_max = min(ans_max, max_search(r[i], c[i]));
    } else {
      ans_min = max(ans_min, min_search(r[i], c[i]));
    }
  }

  if (ans_min > ans_max) {
    return -1;
  } else {
    return ans_min;
  }
}

void reset() {
  fill(r, r + m + 1, 0);
  fill(c, c + m + 1, 0);
  fill(o, o + m + 1, 0);
  return;
}

int main() {
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 1; i <= n; i++) {
    a[i].resize(k + 1);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 2; i <= n; i++) {
      a[i][j] = a[i - 1][j] | a[i][j];
    }
  }

  while (q--) {
    printf("%d\n", solve());
    reset();
  }

  return 0;
}
