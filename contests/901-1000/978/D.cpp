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
ll a[int(1e5 + 5)], b[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  if (n <= 2) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1e9;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      a[1] = b[1] + di;
      a[2] = b[2] + dj;

      for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + (a[i - 1] - a[i - 2]);
      }

      bool flag = true;
      int now = 0;
      for (int i = 1; i <= n; i++) {
        if (abs(a[i] - b[i]) >= 2) {
          flag = false;
          break;
        }
        now += abs(a[i] - b[i]);
      }

      if (flag) {
        ans = min(ans, now);
      }
    }
  }

  cout << (ans == 1e9 ? -1 : ans) << endl;

  return 0;
}
