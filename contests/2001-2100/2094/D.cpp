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

string p, s;
vector<pair<char, int>> vp, vs;

void solve() {
  cin >> p;
  vp.resize(0);
  int cnt = 1;
  for (int i = 1; i < p.length(); i++) {
    if (p[i] == p[i - 1]) {
      cnt++;
    } else {
      vp.push_back({p[i - 1], cnt});
      cnt = 1;
    }
  }
  vp.push_back({p[p.length() - 1], cnt});

  cin >> s;
  vs.resize(0);
  cnt = 1;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      vs.push_back({s[i - 1], cnt});
      cnt = 1;
    }
  }
  vs.push_back({s[s.length() - 1], cnt});

  if (vp.size() != vs.size()) {
    NO();
    return;
  }

  for (int i = 0; i < vp.size(); i++) {
    if (vp[i].first != vs[i].first) {
      NO();
      return;
    }
    if (vp[i].second > vs[i].second || vp[i].second * 2 < vs[i].second) {
      NO();
      return;
    }
  }

  YES();
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
