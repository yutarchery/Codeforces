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
char s[int(4e5 + 5)];

pair<char, int> p[int(4e5 + 5)];
bool erased[int(4e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    p[i] = {s[i], i};
  }
  sort(p + 1, p + n + 1);

  for (int i = 1; i <= k; i++) {
    erased[p[i].second] = true;
  }

  for (int i = 1; i <= n; i++) {
    if (erased[i]) {
      continue;
    }
    cout << s[i];
  }
  cout << '\n';

  return 0;
}
