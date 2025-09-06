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

ll num[19];

void solve() {
  ll n;
  cin >> n;

  vector<ll> ans;
  for (int i = 1; i <= 18; i++) {
    if (n % num[i] == 0) {
      ans.push_back(n / num[i]);
    }
  }
  sort(ans.begin(), ans.end());

  int k = ans.size();
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i] << (i == k - 1 ? '\n' : ' ');
  }
  return;
}

int main() {
  num[1] = 11;
  for (int i = 2; i <= 18; i++) {
    num[i] = (num[i - 1] - 1) * 10 + 1;
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
