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

vector<ll> primes;
bool visited[int(1e7 + 5)];
ll sum_p[int(7e5 + 5)];

void prepare() {
  primes.push_back(0);
  for (int i = 2; i <= int(1e7); i++) {
    if (visited[i]) {
      continue;
    }

    primes.push_back(i);
    for (int j = i; j <= int(1e7); j += i) {
      visited[j] = true;
    }
  }

  for (int i = 1; i < primes.size(); i++) {
    sum_p[i] = sum_p[i - 1] + primes[i];
  }

  return;
}

int n;
ll a[int(4e5 + 5)], sum[int(4e5 + 5)];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<ll>());
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  if (n == 1) {
    return 0;
  }

  if (sum[n] >= sum_p[n]) {
    return 0;
  }

  int ok = 1, ng = n;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (sum[mid] >= sum_p[mid]) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return n - ok;
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
