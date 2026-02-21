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

ll solve() {
  ll n, k;
  cin >> n >> k;

  map<ll, bool> visited;
  map<ll, ll> mp;

  priority_queue<Pll, vector<Pll>, greater<Pll>> que;
  que.push({0, n});

  while (!que.empty()) {
    Pll q = que.top();
    que.pop();

    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    mp[q.second] = q.first;

    que.push({q.first + 1, (q.second + 1) / 2});
    que.push({q.first + 1, q.second / 2});
  }

  if (!visited[k]) {
    return -1;
  } else {
    return mp[k];
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
