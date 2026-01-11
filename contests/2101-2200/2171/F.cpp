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

int n, p[int(2e5 + 5)];
int group[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int calc_group(int i) {
  if (group[i] == i) {
    return i;
  } else {
    int res = calc_group(group[i]);
    return group[i] = res;
  }
}

void solve() {
  cin >> n;
  fill(visited, visited + n + 1, false);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  set<int> rest;
  set<Pii> ans;
  for (int i = 1; i <= n; i++) {
    if (!visited[p[i]]) {
      int r = p[i];
      for (int j = p[i]; j <= n; j++) {
        if (!visited[j]) {
          r = j;
          visited[j] = true;
          rest.insert(j);
        } else {
          break;
        }
      }

      auto iter = rest.end();
      iter--;

      for (int j = p[i]; j <= r; j++) {
        if (j != p[i]) {
          ans.insert({p[i], j});
        }
        group[j] = group[(*iter)];
      }
      ans.insert({p[i], (*iter)});
    }

    rest.erase(p[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (calc_group(i) != n) {
      No();
      return;
    }
  }
  Yes();
  for (Pii a : ans) {
    cout << a.first << " " << a.second << endl;
  }

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
