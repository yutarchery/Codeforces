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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, p[int(1e5 + 5)];
int a[int(1e5 + 5)];
char ans[int(1e5 + 5)];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  int l = 3, r = n;
  ans[1] = 'L', ans[2] = 'L';
  a[1] = p[1], a[2] = p[2];

  for (int i = 3; i <= n; i += 2) {
    if (a[i - 2] < a[i - 1]) {
      if (p[l] < p[r]) {
        ans[i] = 'R', ans[i + 1] = 'L';
        a[i] = p[r], a[i + 1] = p[l];
      } else {
        ans[i] = 'L', ans[i + 1] = 'R';
        a[i] = p[l], a[i + 1] = p[r];
      }
    } else {
      if (p[l] > p[r]) {
        ans[i] = 'R', ans[i + 1] = 'L';
        a[i] = p[r], a[i + 1] = p[l];
      } else {
        ans[i] = 'L', ans[i + 1] = 'R';
        a[i] = p[l], a[i + 1] = p[r];
      }
    }

    l++;
    r--;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';

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
