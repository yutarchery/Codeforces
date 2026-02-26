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

int n, b[int(2e5 + 5)];

int solve() {
  cin >> n;
  priority_queue<int> que;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] > 0) {
      que.push(b[i]);
    }
  }

  int b1 = que.top();
  que.pop();

  int rest = n - b1;
  while (rest > 0) {
    int q = que.top();
    que.pop();

    if (q - 1 > 0) {
      que.push(q - 1);
    }
    rest--;
  }

  return que.size() + 1;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
