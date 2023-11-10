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

int t, l, r;

int min_prime(int num) {
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return i;
    }
  }

  return 1;
}

void solve() {
  for (int i = l; i <= r; i++) {
    int a = min_prime(i);
    if (a == 1) {
      continue;
    }
    cout << a << " " << i - a << endl;
    return;
  }

  cout << -1 << endl;
  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> l >> r;
    solve();
  }

  return 0;
}