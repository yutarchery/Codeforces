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

int t, q, idx;
string s;
const string u = "1100";
char v;

bool judge(int start) {
  if (int(s.length()) <= 3) {
    return false;
  }

  if (start < 0 || start + 3 >= s.length()) {
    return false;
  }

  for (int j = 0; j < u.length(); j++) {
    if (s[start + j] != u[j]) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (judge(i)) {
      cnt++;
    }
  }

  cin >> q;

  for (int i = 1; i <= q; i++) {
    cin >> idx >> v;
    idx--;
    int now = 0;
    for (int j = -3; j <= 3; j++) {
      if (judge(idx + j)) {
        now--;
      }
    }
    s[idx] = v;
    for (int j = -3; j <= 3; j++) {
      if (judge(idx + j)) {
        now++;
      }
    }
    cnt += now;

    if (cnt >= 1) {
      YES();
    } else {
      NO();
    }
  }
  return;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}
