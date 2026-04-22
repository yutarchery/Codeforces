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

int n;
char s[int(1e5 + 5)][2];

ll cnt[26][26];

ll solve() {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      cnt[i][j] = 0;
    }
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    cnt[s[i][0] - 'a'][s[i][1] - 'a']++;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (j != s[i][0] - 'a') {
        ans += cnt[j][s[i][1] - 'a'];
      }

      if (j != s[i][1] - 'a') {
        ans += cnt[s[i][0] - 'a'][j];
      }
    }

    cnt[s[i][0] - 'a'][s[i][1] - 'a']--;
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
