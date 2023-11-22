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

int t, n;
ll a[int(2e5 + 5)], b[int(2e5 + 5)], ans[int(2e5 + 5)];
map<ll, ll> mp;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 1; j <= n; j++) {
      cin >> a[j];
      b[j] = a[j];
    }
    sort(b + 1, b + n + 1);

    fill(ans, ans + n + 1, 0);
    for (int j = 1; j <= n; j++) {
      ans[1] += b[j] - b[1] + 1;
    }

    for (ll j = 2; j <= n; j++) {
      ans[j] = ans[j - 1] + (b[j] - b[j - 1]) * (2 * j - n - 2);
    }
    for (int j = 1; j <= n; j++) {
      mp[b[j]] = ans[j];
    }

    cout << mp[a[1]];
    for (int j = 2; j <= n; j++) {
      cout << " " << mp[a[j]];
    }
    cout << endl;
  }

  return 0;
}