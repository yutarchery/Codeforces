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
ll a[int(2e5 + 5)], sum[int(2e5 + 5)], prod[int(2e5 + 5)];

void solve() {
  cin >> n;
  vector<int> indexes;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 1) {
      indexes.push_back(i);
    }
  }

  if (indexes.size() == 0) {
    cout << "1 1" << endl;
    return;
  }

  int l = indexes[0], r = indexes[indexes.size() - 1];

  prod[l - 1] = 1;
  for (int i = l; i <= r; i++) {
    sum[i] = sum[i - 1] + a[i];
    prod[i] = prod[i - 1] * a[i];
    if (prod[i] > ll(1e9)) {
      cout << l << " " << r << endl;
      return;
    }
  }

  ll max_value = 0;
  int ans_l = 1, ans_r = 1;
  for (int i = 0; i < indexes.size(); i++) {
    for (int j = i; j < indexes.size(); j++) {
      int now_l = indexes[i], now_r = indexes[j];
      ll now_value = sum[now_l - 1] + (prod[now_r] / prod[now_l - 1]) +
                     (sum[r] - sum[now_r]);

      if (now_value > max_value) {
        max_value = now_value;
        ans_l = now_l;
        ans_r = now_r;
      }
    }
  }

  cout << ans_l << " " << ans_r << endl;
  return;
}

void reset() {
  fill(a + 1, a + n + 1, 0);
  fill(sum + 1, sum + n + 1, 0);
  fill(prod + 1, prod + n + 1, 0);
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