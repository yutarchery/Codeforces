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
string s;
bool period[int(2e5 + 5)], visited[int(2e5 + 5)];

bool is_c(char c) { return (c == 'b' || c == 'c' || c == 'd'); }

bool have_period(int idx) {
  if (idx == n) {
    return period[idx] = true;
  }
  if (visited[idx]) {
    return period[idx];
  }

  visited[idx] = true;

  bool ans = false;
  if (idx + 2 <= n && is_c(s[idx]) && !is_c(s[idx + 1])) {
    ans = ans | have_period(idx + 2);
  }
  if (idx + 3 <= n && is_c(s[idx]) && !is_c(s[idx + 1]) && is_c(s[idx + 2])) {
    ans = ans | have_period(idx + 3);
  }

  return period[idx] = ans;
}

void solve() {
  cin >> n;
  cin >> s;

  fill(period, period + n, false);
  fill(visited, visited + n, false);
  have_period(0);

  for (int i = 0; i < n; i++) {
    if (i > 0 && period[i]) {
      cout << ".";
    }
    cout << s[i];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
