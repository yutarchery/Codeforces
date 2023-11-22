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

int t, x, y;
int min_prime[int(1e7 + 5)];

int solve() {
  if (y - x == 1) {
    return -1;
  }

  int ans = 1e9, rest = y - x;
  while (rest > 1) {
    int p = min_prime[rest];
    ans = min(ans, ((x + p - 1) / p) * p - x);
    while (rest % p == 0) {
      rest /= p;
    }
  }

  return ans;
}

int main() {
  for (int i = 2; i <= int(1e7); i++) {
    if (min_prime[i] != 0) {
      continue;
    }
    for (int j = i; j <= int(1e7); j += i) {
      min_prime[j] = i;
    }
  }

  cin >> t;
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", solve());
  }

  return 0;
}