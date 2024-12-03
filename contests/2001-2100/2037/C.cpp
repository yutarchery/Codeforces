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

bool is_composite(int num) {
  if (num == 1) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return true;
    }
  }
  return false;
}

void display(int n, int o, int e) {
  vector<int> ans;
  for (int i = 1; i <= n; i += 2) {
    if (i == o) {
      continue;
    }
    ans.push_back(i);
  }
  ans.push_back(o);
  ans.push_back(e);
  for (int i = 2; i <= n; i += 2) {
    if (i == e) {
      continue;
    }
    ans.push_back(i);
  }

  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    if (i == ans.size() - 1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return;
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i += 2) {
    for (int j = 2; j <= n; j += 2) {
      if (is_composite(i+j)) {
        display(n, i, j);
        return;
      }
    }
  }
  
  printf("-1\n");
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}
