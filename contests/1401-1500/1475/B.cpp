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
bool ans[int(1e6 + 5)];

void prepare(int num) {
  if (num + 2020 <= int(1e6) && !ans[num + 2020]) {
    ans[num + 2020] = true;
    prepare(num + 2020);
  }

  if (num + 2021 <= int(1e6) && !ans[num + 2021]) {
    ans[num + 2021] = true;
    prepare(num + 2021);
  }

  return;
}

int main() {
  prepare(0);

  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);

    if (ans[n]) {
      YES();
    } else {
      NO();
    }
  }

  return 0;
}