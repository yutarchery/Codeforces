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

int t;
string s;

bool solve() {
  bool flag = false;

  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      swap(s[i], s[j]);
      if (s == "abc") {
        flag = true;
      }
      swap(s[i], s[j]);
    }
  }

  return flag;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s;
    if (solve() || s == "abc") {
      YES();
    } else {
      NO();
    }
  }

  return 0;
}