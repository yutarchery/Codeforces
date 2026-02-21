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
char s[55];

char solve() {
  cin >> n;

  int cnt_a = 0, cnt_b = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    if (s[i] == 'A') {
      cnt_a++;
    } else {
      cnt_b++;
    }
  }

  if (s[n] == 'A') {
    if (s[1] == 'A') {
      return 'A';
    } else {
      return s[n - 1];
    }
  } else {
    if (cnt_b == 1) {
      return 'A';
    } else {
      return 'B';
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << (solve() == 'A' ? "Alice" : "Bob") << endl;
  }

  return 0;
}
