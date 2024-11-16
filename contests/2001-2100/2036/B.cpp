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

int t, n, k, b[int(2e5 + 5)], c[int(2e5 + 5)];
map<int, int> mp;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
      scanf("%d %d", &b[i], &c[i]);
      mp[b[i]] += c[i];
    }
    vector<int> now;
    for (int i = 1; i <= k; i++) {
      if (mp[b[i]] > 0) {
        now.push_back(mp[b[i]]);
        mp[b[i]] = 0;
      }
    }
    sort(now.begin(), now.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < min(int(now.size()), n); i++) {
      ans += now[i];
    }
    printf("%d\n", ans);
  }

  return 0;
}
