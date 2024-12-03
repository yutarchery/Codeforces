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

int k, a[int(2e5 + 5)], cnt[int(2e5 + 5)];

void solve() {
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }

  for (int i = 1; i <= k; i++) {
    if (cnt[i] >= 1 && (k - 2) % i == 0) {
      int j = (k - 2) / i;
      if (i == j && cnt[i] >= 2) {
        printf("%d %d\n", i, j);
        break;
      } else if (i!=j&&cnt[j] >= 1) {
        printf("%d %d\n", i, j);
        break;
      }
    }
  }

  fill(cnt, cnt + k + 1, 0);
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}
