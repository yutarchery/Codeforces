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

vector<int> primes;
bool visited[int(1e5 + 5)];

void prepare() {
  primes.emplace_back(1);
  for (int i = 2; i <= int(1e5); i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    primes.emplace_back(i);
    for (int j = i; j <= int(1e5); j += i) {
      visited[j] = true;
    }
  }

  return;
}

int n, ans[int(1e5 + 5)];

void solve() {
  cin >> n;
  fill(visited, visited + n + 1, false);

  int ok = 0, ng = primes.size();
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (primes[mid] <= n) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  for (int i = ok; i >= 1; i--) {
    queue<int> now;
    for (int j = primes[i]; j <= n; j += primes[i]) {
      if (!visited[j]) {
        visited[j] = true;
        now.push(j);
      }
    }

    now.push(primes[i]);
    while (now.size() >= 2) {
      int q1 = now.front();
      now.pop();
      int q2 = now.front();
      ans[q1] = q2;
    }
  }
  ans[1] = 1;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  prepare();

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
