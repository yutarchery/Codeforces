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
char s[55], t[55];

int cnt_s[26], cnt_t[26];
vector<int> ans;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    cnt_s[s[i] - 'a']++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    cnt_t[t[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt_s[i] != cnt_t[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == t[i]) {
      continue;
    }

    int target = i;
    for (int j = i + 1; j <= n; j++) {
      if (t[i] == s[j]) {
        target = j;
        break;
      }
    }

    for (int j = target - 1; j >= i; j--) {
      ans.emplace_back(j);
      swap(s[j], s[j + 1]);
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
