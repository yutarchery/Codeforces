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

int n, a[int(2e5 + 5)];

int cnt[int(2e5 + 5)], ans[int(2e5 + 5)];

void solve() {
  cin >> n;
  fill(cnt, cnt + n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  priority_queue<Pii> que;
  bool flag = true;
  for (int i = 0; i <= n; i++) {
    if (flag) {
      que.push({cnt[i], i});

      if (cnt[i] == 0) {
        flag = false;
      }
    }

    while (!que.empty()) {
      Pii q = que.top();
      if (q.first > n - i) {
        que.pop();
      } else {
        break;
      }
    }
    ans[i] = que.size();
  }

  for (int i = n; i >= 0; i--) {
    cout << ans[i] << (i == 0 ? '\n' : ' ');
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
