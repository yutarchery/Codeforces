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
ll a[int(2e5 + 5)], sum[int(2e5 + 5)];

bool solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i % 2 != 0) {
      sum[i] = sum[i - 1] + a[i];
    } else {
      sum[i] = sum[i - 1] - a[i];
    }
  }
  sort(sum, sum + n + 1);

  for (int i = 0; i <= n - 1; i++) {
    if (sum[i] == sum[i + 1]) {
      return true;
    }
  }

  return false;
}

void reset() {
  fill(a, a + n + 1, 0);
  fill(sum, sum + n + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (solve()) {
      YES();
    } else {
      NO();
    }
    reset();
  }
  return 0;
}
