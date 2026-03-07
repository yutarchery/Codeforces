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

int n, m, l[int(5e4 + 5)];
vector<int> s[int(5e4 + 5)];

int cnt[int(1e5 + 5)];

bool my_comp(int i, int j) {
  if (l[i] != l[j]) {
    return l[i] < l[j];
  } else {
    return i < j;
  }
}

void solve() {
  cin >> n >> m;
  fill(cnt, cnt + m + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    s[i].resize(l[i]);
    for (int j = 0; j < l[i]; j++) {
      cin >> s[i][j];
      cnt[s[i][j]]++;
    }
  }

  for (int i = 1; i <= m; i++) {
    if (cnt[i] == 0) {
      NO();
      return;
    }
  }

  int now = 1;
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 0; j < l[i]; j++) {
      if (cnt[s[i][j]] == 1) {
        flag = false;
      }
    }

    if (!flag) {
      continue;
    }

    now++;

    if (now >= 3) {
      YES();
      return;
    }
  }

  NO();
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
