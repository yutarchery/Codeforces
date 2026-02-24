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

int n, a[int(2e5 + 5)];

map<int, int> idx;
int before_idx[int(2e5 + 5)], cnt[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    if (idx[a[i] - 1] == 0) {
      cnt[i] = 1;
    } else {
      cnt[i] = cnt[idx[a[i] - 1]] + 1;
      before_idx[i] = idx[a[i] - 1];
    }
    idx[a[i]] = i;
  }

  int k = 0, node;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (k < cnt[i]) {
      k = cnt[i];
      node = i;
    }
  }
  while (node != 0) {
    ans.push_back(node);
    node = before_idx[node];
  }
  reverse(ans.begin(), ans.end());

  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i] << (i == k - 1 ? '\n' : ' ');
  }

  return 0;
}
