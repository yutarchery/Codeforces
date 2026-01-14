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

int n, k, x, a[int(2e5 + 5)];
int l[int(2e5 + 5)], r[int(2e5 + 5)];

void prepare(int gap) {
  r[0] = -1;
  for (int i = 1; i <= n; i++) {
    l[i] = max(0, a[i] - (gap - 1));
    r[i] = min(x, a[i] + (gap - 1));
  }
  l[n + 1] = x + 1;
  return;
}

int cnt(int gap) {
  prepare(gap);
  int res = 0;
  for (int i = 1; i <= n + 1; i++) {
    res += max(0, (l[i] - 1) - r[i - 1]);
  }

  return res;
}

void display(int gap) {
  if (gap == 0) {
    for (int i = 0; i < k; i++) {
      cout << i << (i == k - 1 ? '\n' : ' ');
    }
    return;
  }

  prepare(gap);
  vector<int> ans;
  for (int i = 1; i <= n + 1; i++) {
    if ((l[i] - 1) - r[i - 1] >= 1) {
      for (int j = r[i - 1] + 1; j <= l[i] - 1; j++) {
        if (ans.size() >= k) {
          break;
        }

        ans.push_back(j);
      }
    }
  }

  for (int i = 0; i < k; i++) {
    cout << ans[i] << (i == k - 1 ? '\n' : ' ');
  }

  return;
}

void solve() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int ok = 0, ng = int(1e9 + 5);
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (cnt(mid) >= k) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  display(ok);
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
