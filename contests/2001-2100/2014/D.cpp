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

int t, n, d, k, l, r, cnt[int(1e5 + 5)];

void solve() {
  scanf("%d %d %d", &n, &d, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d %d", &l, &r);
    cnt[max(1, l - d + 1)]++;
    cnt[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
  }

  int now_b = 0, now_m = k + 1, ans_b = 0, ans_m = 0;
  for (int i = 1; i <= n - d + 1; i++) {
    if (now_b < cnt[i]) {
      now_b = cnt[i];
      ans_b = i;
    }
    if (now_m > cnt[i]) {
      now_m = cnt[i];
      ans_m = i;
    }
  }

  printf("%d %d\n", ans_b, ans_m);
  return;
}

void reset() {
  fill(cnt, cnt + n + 2, 0);
  return;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
    reset();
  }

  return 0;
}
