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

int solve() {
  cin >> n;
  int min_element = 1e9 + 5, min_index = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    if (a[i] < min_element) {
      min_element = a[i];
      min_index = i;
    }
  }

  for (int i = min_index; i + 1 <= n; i++) {
    if (a[i] <= a[i + 1]) {
      continue;
    }
    return -1;
  }

  return min_index - 1;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}
