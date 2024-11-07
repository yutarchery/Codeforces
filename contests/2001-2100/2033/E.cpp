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

int n, p[int(1e6 + 5)];
bool visited[int(1e6 + 5)];

int solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    int cnt = 0, now = i;
    while (!visited[now]) {
      visited[now] = true;
      cnt++;
      now = p[now];
    }
    ans += (cnt - 1) / 2;
  }

  return ans;
}

void reset() {
  fill(p + 1, p + n + 1, 0);
  fill(visited + 1, visited + n + 1, false);
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
