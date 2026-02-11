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

void solve() {
  int q, s, k;
  deque<ll> que;
  bool reversed = false;
  ll sum = 0, ans = 0, n = 0;

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s;

    if (s == 1) {
      if (!reversed) {
        ll a = que.back();
        que.pop_back();
        ans = ans - n * a + sum;
        que.push_front(a);
      } else {
        ll a = que.front();
        que.pop_front();
        ans = ans - n * a + sum;
        que.push_back(a);
      }
    } else if (s == 2) {
      reversed = !reversed;
      ans = sum * (n + 1) - ans;
    } else {
      cin >> k;

      sum += k;
      n++;
      ans = ans + n * k;

      if (!reversed) {
        que.push_back(k);
      } else {
        que.push_front(k);
      }
    }

    cout << ans << endl;
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
