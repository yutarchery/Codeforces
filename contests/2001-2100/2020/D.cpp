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

int n, m, a[int(2e5 + 5)], d[int(2e5 + 5)], k[int(2e5 + 5)];
int cnt[int(2e5 + 55)][11];

vector<int> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];

void prepare() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> d[i] >> k[i];
    cnt[a[i]][d[i]]++;
    cnt[a[i] + d[i] * k[i]][d[i]]--;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 10; j++) {
      if (i + j <= n) {
        cnt[i + j][j] += cnt[i][j];
      }
      if (cnt[i][j] > 0) {
        graph[i].push_back(i + j);
        graph[i + j].push_back(i);
      }
    }
  }

  return;
}

int solve() {
  prepare();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }
    ans++;
    queue<int> que;
    que.push(i);

    while (!que.empty()) {
      int q = que.front();
      que.pop();
      for (int next : graph[q]) {
        if (!visited[next]) {
          visited[next] = true;
          que.push(next);
        }
      }
    }
  }

  return ans;
}

void reset() {
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
    fill(cnt[i], cnt[i] + 11, 0);
  }
  fill(visited, visited + n + 1, false);

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
