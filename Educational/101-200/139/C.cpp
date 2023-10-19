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

int t, n;
string s[2];
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

bool judge(int start_i, int start_j, int j_dir) {
  bool visited[2][int(2e5 + 5)] = {};

  queue<Pii> que;
  que.push({start_i, start_j});
  visited[start_i][start_j] = true;

  while (!que.empty()) {
    Pii q = que.front();
    int i = q.first, j = q.second;
    que.pop();

    if (!visited[1 - i][j] && s[1 - i][j] == 'B') {
      visited[1 - i][j] = true;
      que.push({1 - i, j});
      continue;
    }

    if (!visited[i][j + j_dir] && s[i][j + j_dir] == 'B') {
      visited[i][j + j_dir] = true;
      que.push({i, j + j_dir});
      continue;
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'B' && !visited[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  bool flag = false;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < 2; i++) {
      if (s[i][j] == 'B') {
        flag = true;
        if (judge(i, j, 1)) {
          YES();
          return;
        }
      }
    }
    if (flag) {
      break;
    }
  }

  flag = false;
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i < 2; i++) {
      if (s[i][j] == 'B') {
        flag = true;
        if (judge(i, j, -1)) {
          YES();
          return;
        }
      }
    }
    if (flag) {
      break;
    }
  }

  NO();
  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < 2; j++) {
      cin >> s[j];
    }
    solve();
  }

  return 0;
}