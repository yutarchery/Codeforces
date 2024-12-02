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

int n, m;
bool visited[1005][1005];
char c[1005][1005];

const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};

void prepare() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  return;
}

int calc(int num) {
  string now = "";
  int i = num, j = num, k = 0;
  while (!visited[i][j] && k <= 3) {
    visited[i][j] = true;
    now += c[i][j];

    if (visited[i + di[k]][j + dj[k]] || c[i + di[k]][j + dj[k]] < '0' ||
        '9' < c[i + di[k]][j + dj[k]]) {
      k++;
    }
    if (k >= 4) {
      break;
    }
    i += di[k];
    j += dj[k];
  }

  for (int l = 0; l < 3; l++) {
    now += now[l];
  }

  int ans = 0;
  for (int l = 0; l + 3 < now.length(); l++) {
    if (now[l] == '1' && now[l + 1] == '5' && now[l + 2] == '4' &&
        now[l + 3] == '3') {
      ans++;
    }
  }

  return ans;
}

int solve() {
  prepare();
  int ans = 0;
  for (int i = 1; i <= min(n, m) / 2; i++) {
    ans += calc(i);
  }
  return ans;
}

void reset() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c[i][j] = 'a';
      visited[i][j] = false;
    }
  }

  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", solve());
    reset();
  }

  return 0;
}
