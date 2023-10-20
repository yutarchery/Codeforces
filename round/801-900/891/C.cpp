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

int t, n, a[int(1e6 + 5)];

int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n * (n - 1) / 2; j++) {
      scanf("%d", &a[j]);
    }
    sort(a, a + n * (n - 1) / 2);

    vector<int> ans;
    int idx = 0, now = n - 1;
    while (idx < n * (n - 1) / 2) {
      ans.push_back(a[idx]);
      idx += now;
      now--;
    }
    ans.push_back(a[n * (n - 1) / 2 - 1]);

    cout << ans[0];
    for (int j = 1; j < n; j++) {
      cout << " " << ans[j];
    }
    cout << endl;
  }

  return 0;
}