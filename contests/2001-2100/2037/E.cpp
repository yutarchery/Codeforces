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

char ans[int(1e4 + 5)];
int res[int(1e4 + 5)];

void solve() {
  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    cout << "? 1 " << i << endl;
    cin >> res[i];
  }

  if (res[n] == 0) {
    cout << "! IMPOSSIBLE" << endl;
    return;
  }

  bool flag = false;
  for (int i = 2; i <= n; i++) {
    if (res[i] == 0) {
      continue;
    } else if (!flag) {
      flag = true;
      ans[i] = '1';
      for (int j = 1; j <= res[i]; j++) {
        ans[i - j] = '0';
      }
      for (int j = res[i] + 1; i - j >= 1; j++) {
        ans[i - j] = '1';
      }
    } else {
      if (res[i] == res[i - 1]) {
        ans[i] = '0';
      } else {
        ans[i] = '1';
      }
    }
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;

  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}
