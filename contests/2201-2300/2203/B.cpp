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

int solve() {
  ll x;
  cin >> x;

  ll sum = 0;
  vector<ll> rest;
  while (x >= 10) {
    rest.push_back(x % 10);
    sum += x % 10;
    x /= 10;
  }
  sum += x;
  rest.push_back(x - 1);

  sort(rest.begin(), rest.end(), greater<ll>());

  int ans = 0;
  for (int i = 0; i < rest.size(); i++) {
    if (sum < 10) {
      return ans;
    }

    ans++;
    sum -= rest[i];
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
