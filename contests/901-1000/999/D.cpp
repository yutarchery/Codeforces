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

int n, m;
ll a[int(2e5 + 5)];

queue<int> que[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    que[a[i] % m].push(i);
  }

  deque<int> shortage;
  for (int i = 0; i < m; i++) {
    if (que[i].size() < n / m) {
      shortage.push_back(i);
    }
  }

  ll ans = 0;
  for (int i = 0; i < m; i++) {
    if (que[i].size() <= n / m) {
      continue;
    }

    int rest = que[i].size() - n / m;
    while (rest > 0) {
      int target = shortage.front();
      shortage.pop_front();
      if (target < i) {
        shortage.push_back(target + m);
        continue;
      }

      int q = que[i].front();
      que[i].pop();

      ans += target - i;
      a[q] += target - i;
      rest--;
      que[target % m].push(q);

      if (que[target % m].size() < n / m) {
        shortage.push_front(target);
      }
    }
  }

  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
