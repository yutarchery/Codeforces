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

bool visited[int(1e5 + 5)];
set<int> divisors[int(1e5 + 5)];

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
    auto iter = divisors[num / i].begin();
    while (iter != divisors[num / i].end()) {
      divisors[num].insert(*iter);
      divisors[num].insert(*iter * i);
      iter++;
    }
    break;
  }

  divisors[num].insert(1);
  divisors[num].insert(num);
  return;
}

ll n, a[int(1e5 + 5)], cnt[int(1e5 + 5)], sum[int(1e5 + 5)];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  for (ll i = 1; i <= n; i++) {
    auto iter = divisors[a[i]].begin();
    while (iter != divisors[a[i]].end()) {
      sum[*iter] += cnt[*iter] * (n - i);
      cnt[*iter]++;
      iter++;
    }
  }

  ll ans = 0;
  for (ll i = ll(1e5); i >= 1; i--) {
    ans += i * sum[i];

    auto iter = divisors[i].begin();
    while (iter != divisors[i].end()) {
      sum[*iter] -= sum[i];
      iter++;
    }
  }

  fill(cnt + 1, cnt + int(1e5 + 1), 0);
  fill(sum + 1, sum + int(1e5 + 1), 0);
  return ans;
}

int main() {
  for (int i = 1; i <= int(1e5); i++) {
    prepare_divisors(i);
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}
