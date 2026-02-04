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

int n, k, l, r;
ll a[int(2e5 + 5)];

ll solve() {
  cin >> n >> k >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<ll, int> cnt_l, cnt_r;
  int l_idx = 0, r_idx = 0;
  set<ll> st_l, st_r;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    l_idx = max(l_idx, i - 1);
    r_idx = max(r_idx, i - 1);

    while (l_idx < n) {
      if (cnt_l[a[l_idx + 1]] == 0) {
        if (st_l.size() == k - 1) {
          break;
        }
      }

      l_idx++;
      st_l.insert(a[l_idx]);
      cnt_l[a[l_idx]]++;
    }

    while (r_idx < n) {
      if (cnt_r[a[r_idx + 1]] == 0) {
        if (st_r.size() == k) {
          break;
        }
      }
      r_idx++;
      st_r.insert(a[r_idx]);
      cnt_r[a[r_idx]]++;
    }

    if (st_l.size() == k - 1 && st_r.size() == k) {
      int now_l = max(i + l - 2, l_idx);
      int now_r = min(i + r - 1, r_idx);
      ans += max(0, now_r - now_l);
    }

    if (cnt_l[a[i]] >= 1) {
      cnt_l[a[i]]--;
      if (cnt_l[a[i]] == 0) {
        st_l.erase(a[i]);
      }
    }
    cnt_r[a[i]]--;
    if (cnt_r[a[i]] == 0) {
      st_r.erase(a[i]);
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
