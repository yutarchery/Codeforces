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

int n, a[int(1e5 + 5)], c[int(1e5 + 5)], input_cnt[int(1e5 + 5)];
bool visited[int(1e5 + 5)];
vector<int> ans;

void loop_search(int start) {
  bool searched[int(1e5 + 5)] = {};
  vector<Pii> p;

  int now = start;
  while (!searched[now]) {
    searched[now] = true;
    p.push_back({c[now], now});
    now = a[now];
  }
  sort(p.begin(), p.end());

  now = a[p[0].second];
  while (!visited[now]) {
    visited[now] = true;
    ans.push_back(now);
    now = a[now];
  }
  return;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    input_cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (input_cnt[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    ans.push_back(q);
    visited[q] = true;
    input_cnt[a[q]]--;

    if (input_cnt[a[q]] == 0) {
      que.push(a[q]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      loop_search(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

void reset() {
  fill(a + 1, a + n + 1, 0);
  fill(c + 1, c + n + 1, 0);
  fill(input_cnt + 1, input_cnt + n + 1, 0);
  fill(visited + 1, visited + n + 1, false);
  ans.resize(0);

  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    reset();
  }

  return 0;
}