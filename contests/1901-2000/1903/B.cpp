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

int n, m[1005][1005], a[1005];

bool solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> m[i][j];
      if (i != j) {
        a[i] = m[i][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }

      a[i] &= m[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }

      if ((a[i] | a[j]) != m[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void display() {
  for (int i = 1; i <= n; i++) {
    cout << a[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

void reset() {
  for (int i = 1; i <= n; i++) {
    fill(m[i] + 1, m[i] + n + 1, 0);
  }
  fill(a + 1, a + n + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    if (solve()) {
      YES();
      display();
    } else {
      NO();
    }

    reset();
  }

  return 0;
}
