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

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

int n;
ll a[int(1e5 + 5)];

bool visited[105];
set<ll> primes;

void prepare() {
  for (int i = 2; i <= 100; i++) {
    if (visited[i]) {
      continue;
    }
    primes.insert(i);
    for (int j = i; j <= 100; j += i) {
      visited[j] = true;
    }
  }

  return;
}

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll g = a[1];
  for (int i = 1; i <= n; i++) {
    g = my_gcd(a[i], g);
  }

  for (ll p : primes) {
    if (g % p != 0) {
      return p;
    }
  }

  return -1;
}

int main() {
  prepare();

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
