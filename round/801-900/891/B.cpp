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

string solve(string s) {
  string t = "";
  bool flag = false;

  for (int i = 0; i < s.length(); i++) {
    if (flag) {
      t += "0";
      continue;
    }

    if ('5' <= s[i] && s[i] <= '9') {
      flag = true;

      for (int j = i - 1; j >= 0; j--) {
        t[j]++;
        if (t[j] == '5') {
          t[j] = '0';
        } else {
          break;
        }
      }

      t += "0";
    } else {
      t += s[i];
    }
  }

  if (t[0] == '0') {
    t = "1" + t;
  }

  return t;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }

  return 0;
}