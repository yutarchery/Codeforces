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
  ll sum = 0, ans0 = 0, ans1 = 0, m = 0;

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s;

    if (s == 1) {
      if (!reversed) {
        ll a = que.back();
        que.pop_back();
        ans0 = (ans0 - m * a) + sum;
        ans1 = (ans1 - sum) + m * a;
        que.push_front(a);
      } else {
        ll a = que.front();
        que.pop_front();

        ans1 = (ans1 - m * a) + sum;
        ans0 = (ans0 - sum) + m * a;
        que.push_back(a);
      }
    } else if (s == 2) {
      reversed = !reversed;
    } else {
      cin >> k;

      sum += k;
      m++;

      if (!reversed) {
        que.push_back(k);
        ans0 = ans0 + m * k;
        ans1 = ans1 + sum;
      } else {
        que.push_front(k);
        ans1 = ans1 + m * k;
        ans0 = ans0 + sum;
      }
    }

    if (!reversed) {
      cout << ans0 << endl;
    } else {
      cout << ans1 << endl;
    }
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
