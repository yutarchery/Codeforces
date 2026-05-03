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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, k;
char s[int(1e5 + 5)];
int cnt[26];

void solve() {
  cin >> n >> k;

  fill(cnt, cnt + 26, 0);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    cnt[s[i] - 'a']++;
  }

  int odds = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 1) {
      odds++;
    }
  }

  if (odds - 1 <= k) {
    YES();
  } else {
    NO();
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
