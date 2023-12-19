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

set<int> divisors[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

void prepare_divisors(int num) {
  if (visited[num]) {
    return;
  }

  visited[num] = true;
  for (int i = 2; i * i <= num; i++) {
    if (num % i != 0) {
      continue;
    }

    prepare_divisors(num / i);
    for (int d : divisors[num / i]) {
      divisors[num].insert(d);
      divisors[num].insert(i * d);
    }
    break;
  }

  divisors[num].insert(1);
  divisors[num].insert(num);
  return;
}

int n;
ll a[int(2e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  prepare_divisors(n);

  ll ans = 0;
  for (int k : divisors[n]) {
    int cnt = 0;
    ll now_weight = 0, min_weight = ll(1e18), max_weight = 0;

    for (int i = 1; i <= n; i++) {
      cnt++;
      now_weight += a[i];

      if (cnt == k) {
        min_weight = min(min_weight, now_weight);
        max_weight = max(max_weight, now_weight);
        cnt = 0;
        now_weight = 0;
      }
    }

    ans = max(ans, max_weight - min_weight);
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}
