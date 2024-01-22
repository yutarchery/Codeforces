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
int a[int(3e5 + 5)], d[int(3e5 + 5)];

int ans[int(3e5 + 5)];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
  }

  set<int> alive, searching, dead;
  alive.insert(0);
  alive.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    alive.insert(i);
    searching.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int m : searching) {
      auto before_iter = alive.find(m);
      before_iter--;
      auto after_iter = alive.find(m);
      after_iter++;

      if (a[*before_iter] + a[*after_iter] > d[m]) {
        ans[i]++;
        dead.insert(m);
      }
    }

    for (int m : dead) {
      alive.erase(m);
    }

    searching.clear();
    for (int m : dead) {
      auto before_iter = alive.upper_bound(m);
      before_iter--;
      auto after_iter = alive.upper_bound(m);

      if (0 < *before_iter) {
        searching.insert(*before_iter);
      }
      if (*after_iter <= n) {
        searching.insert(*after_iter);
      }
    }

    dead.clear();
  }

  for (int i = 1; i <= n; i++) {
    printf("%d", ans[i]);
    if (i == n) {
      printf("\n");
    } else {
      printf(" ");
    }
  }

  return;
}

void reset() {
  fill(ans, ans + n + 1, 0);
  fill(a, a + n + 1, 0);
  fill(d, d + n + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    reset();
  }

  return 0;
}
