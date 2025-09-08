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

int n;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];

void solve() {
  cin >> n;
  set<int> rest;
  for (int i = 1; i <= n; i++) {
    rest.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];

    if (a[i] == b[i]) {
      rest.erase(i);
    }
  }

  queue<int> que;
  for (int i = 1; i <= n - 1; i++) {
    if (b[i] == (a[i] ^ a[i + 1])) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    auto iter = rest.find(q);
    if (iter == rest.end()) {
      continue;
    }

    if ((a[q] ^ a[q + 1]) == b[q]) {
      rest.erase(q);
      a[q] = b[q];

      if (rest.find(q - 1) != rest.end()) {
        que.push(q - 1);
      }
    }
  }

  rest.empty() ? YES() : NO();
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
