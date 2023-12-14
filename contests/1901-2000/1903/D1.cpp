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

int n, q;
ll a[int(1e5 + 5)], b[int(1e5 + 5)];
ll k;

ll solve() {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
  }

  ll digit = pow(2, 60), cnt = 0, ans = 0;
  while (digit > 0) {
    ll now_cnt = 0;
    for (int i = 1; i <= n; i++) {
      if ((b[i] & digit) > 0) {
        continue;
      }
      now_cnt += digit - (b[i] % digit);
      if (now_cnt > k) {
        break;
      }
    }

    if (now_cnt + cnt <= k) {
      cnt += now_cnt;
      ans += digit;
      for (int i = 1; i <= n; i++) {
        if ((b[i] & digit) == 0) {
          b[i] += digit - (b[i] % digit);
        }
      }
    }
    digit /= 2;
  }

  return ans;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < q; i++) {
    cin >> k;
    cout << solve() << endl;
  }

  return 0;
}
