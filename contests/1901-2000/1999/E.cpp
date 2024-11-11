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

int t;
ll a, b;

ll cnt[int(2e5 + 5)], sum[int(2e5 + 5)];

int main() {
  for (int i = 1; i <= int(2e5); i++) {
    int rest = i;
    while (rest > 0) {
      cnt[i]++;
      rest /= 3;
    }
    sum[i] = sum[i - 1] + cnt[i];
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &a, &b);
    cout << sum[b] - sum[a - 1] + cnt[a] << endl;
  }

  return 0;
}
