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

int t, a, b, k;
int a_elem[int(2e5 + 5)], b_elem[int(2e5 + 5)];
int cnt_a[int(2e5 + 5)], cnt_b[int(2e5 + 5)];

ll solve() {
  scanf("%d %d %d", &a, &b, &k);

  fill(cnt_a, cnt_a + a + 1, 0);
  fill(cnt_b, cnt_b + b + 1, 0);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a_elem[i]);
    cnt_a[a_elem[i]]++;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &b_elem[i]);
    cnt_b[b_elem[i]]++;
  }

  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    cnt_a[a_elem[i]]--;
    cnt_b[b_elem[i]]--;
    ans += (k - i) - (cnt_a[a_elem[i]] + cnt_b[b_elem[i]]);
  }

  return ans;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    printf("%lld\n", solve());
  }

  return 0;
}