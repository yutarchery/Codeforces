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

int n, m, mm;
int l[int(2e5 + 5)], r[int(2e5 + 5)], x[int(2e5 + 5)], v[int(2e5 + 5)];

int solve() {
  scanf("%d %d %d", &n, &m, &mm);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
  }
  for (int j = 1; j <= m; j++) {
    scanf("%d %d", &x[j], &v[j]);
  }

  int now_j = 1, ans = 0, p = 0;
  priority_queue<int> que;
  for (int i = 1; i <= n; i++) {
    for (int j = now_j; j <= m; j++) {
      if (x[j] <= l[i]) {
        que.push(v[j]);
        now_j++;
      } else {
        break;
      }
    }

    while (p + l[i] <= r[i]) {
      if (que.empty()) {
        return -1;
      }
      p += que.top();
      ans++;
      que.pop();
    }
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
