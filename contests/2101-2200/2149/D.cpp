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
char s[int(2e5 + 5)];

ll sum_al[int(2e5 + 5)], sum_ar[int(2e5 + 5)];
ll sum_bl[int(2e5 + 5)], sum_br[int(2e5 + 5)];

ll solve() {
  cin >> n;
  ll cnt_a = 0, cnt_b = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == 'a') {
      cnt_a++;
    } else {
      cnt_b++;
    }
  }

  fill(sum_al, sum_al + n + 1, 0);
  fill(sum_ar, sum_ar + n + 1, 0);

  fill(sum_bl, sum_bl + n + 1, 0);
  fill(sum_br, sum_br + n + 1, 0);

  int a_idx = 1;
  for (int i = 1; i <= cnt_a; i++) {
    while (s[a_idx] != 'a') {
      a_idx++;
    }

    sum_al[i] = sum_al[i - 1] + abs(a_idx - i);
    a_idx++;
  }

  a_idx = n;
  for (int i = cnt_a; i >= 1; i--) {
    while (s[a_idx] != 'a') {
      a_idx--;
    }
    sum_ar[i] = sum_ar[i + 1] + abs((n - (cnt_a - i)) - a_idx);
    a_idx--;
  }

  int b_idx = 1;
  for (int i = 1; i <= cnt_b; i++) {
    while (s[b_idx] != 'b') {
      b_idx++;
    }

    sum_bl[i] = sum_bl[i - 1] + abs(b_idx - i);
    b_idx++;
  }

  b_idx = n;
  for (int i = cnt_b; i >= 1; i--) {
    while (s[b_idx] != 'b') {
      b_idx--;
    }
    sum_br[i] = sum_br[i + 1] + abs((n - (cnt_b - i)) - b_idx);
    b_idx--;
  }

  ll ans = 1e16;
  for (int i = 0; i <= cnt_a; i++) {
    ans = min(ans, sum_al[i] + sum_ar[i + 1]);
  }
  for (int i = 0; i <= cnt_b; i++) {
    ans = min(ans, sum_bl[i] + sum_br[i + 1]);
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
