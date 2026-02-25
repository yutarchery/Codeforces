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

ll bits[61];

void prepare() {
  bits[0] = 1;
  for (int i = 1; i <= 60; i++) {
    bits[i] = bits[i - 1] * 2;
  }
  return;
}

ll solve() {
  ll s, m;
  cin >> s >> m;
  while (s % 2 == 0 && m % 2 == 0) {
    s /= 2;
    m /= 2;
  }
  if (s % 2 == 1 && m % 2 == 0) {
    return -1;
  }

  ll rest_m = m, idx = 0;
  vector<int> m_bit;
  while (rest_m > 0) {
    if (rest_m % 2 == 1) {
      m_bit.push_back(idx);
    }
    idx++;
    rest_m /= 2;
  }
  reverse(m_bit.begin(), m_bit.end());

  ll ng = 0, ok = s;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    ll rest_s = s;

    for (int i : m_bit) {
      ll now = rest_s / bits[i];
      rest_s -= bits[i] * min(mid, now);
    }

    if (rest_s == 0) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok;
}

int main() {
  prepare();

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
