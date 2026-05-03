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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int q, l, r;
char c;

multiset<Pii> lr, rl;

bool judge() {
  Pii rl_first = *(rl.begin());
  auto iter = lr.lower_bound({rl_first.first + 1, 0});
  return iter != lr.end();
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> q;
  while (q--) {
    cin >> c >> l >> r;
    if (c == '+') {
      lr.insert({l, r});
      rl.insert({r, l});
    } else {
      auto iter = lr.find({l, r});
      lr.erase(iter);
      iter = rl.find({r, l});
      rl.erase(iter);
    }

    judge() ? YES() : NO();
  }

  return 0;
}
