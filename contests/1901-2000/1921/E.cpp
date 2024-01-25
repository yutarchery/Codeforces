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

int h, w, xa, ya, xb, yb;

bool left_same(int xa, int ya, int xb, int yb) {
  for (int i = 1; i <= xb - xa; i++) {
    if (ya == yb) {
      return true;
    }

    if (i % 2 == 1) {
      ya = max(1, ya - 1);
    } else {
      yb = max(1, yb - 1);
    }
  }

  return ya == yb;
}

bool right_same(int xa, int ya, int xb, int yb) {
  for (int i = 1; i <= xb - xa; i++) {
    if (ya == yb) {
      return true;
    }

    if (i % 2 == 1) {
      ya = min(w, ya + 1);
    } else {
      yb = min(w, yb + 1);
    }
  }

  return ya == yb;
}

void solve() {
  cin >> h >> w >> xa >> ya >> xb >> yb;

  if (xa >= xb) {
    cout << "Draw" << endl;
    return;
  }

  if (abs(xa - xb) % 2 != 0) {
    if (ya <= yb && right_same(xa, ya, xb, yb)) {
      cout << "Alice" << endl;
    } else if (yb <= ya && left_same(xa, ya, xb, yb)) {
      cout << "Alice" << endl;
    } else {
      cout << "Draw" << endl;
    }
  } else {
    if (ya <= yb && left_same(xa, ya, xb, yb)) {
      cout << "Bob" << endl;
    } else if (yb <= ya && right_same(xa, ya, xb, yb)) {
      cout << "Bob" << endl;
    } else {
      cout << "Draw" << endl;
    }
  }
  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
