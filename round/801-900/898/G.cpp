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

int solve() {
  vector<int> a_cnt;
  int b_cnt = 0;

  int now = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'B') {
      if (now > 0) {
        a_cnt.push_back(now);
      }
      now = 0;

      if (i + 1 < s.length() && s[i + 1] == 'A') {
        b_cnt++;
      } else if (i - 1 >= 0 && s[i - 1] == 'A') {
        b_cnt++;
      }
    } else {
      now++;
    }
  }
  if (now > 0) {
    a_cnt.push_back(now);
  }
  sort(a_cnt.begin(), a_cnt.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < min(int(a_cnt.size()), b_cnt); i++) {
    ans += a_cnt[i];
  }

  return ans;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s;
    cout << solve() << endl;
  }

  return 0;
}