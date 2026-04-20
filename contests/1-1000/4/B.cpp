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

int d, sum, min_time[50], max_time[50];
int ans[50], sum_min = 0, sum_max = 0;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> d >> sum;
  for (int i = 1; i <= d; i++) {
    cin >> min_time[i] >> max_time[i];

    sum_min += min_time[i];
    sum_max += max_time[i];
  }

  if (sum_min <= sum && sum <= sum_max) {
    YES();

    int rest = sum - sum_min;
    for (int i = 1; i <= d; i++) {
      ans[i] = min_time[i];

      for (int j = 1; j <= max_time[i] - min_time[i]; j++) {
        if (rest > 0) {
          ans[i]++;
          rest--;
        }
      }

      cout << ans[i] << (i == d ? '\n' : ' ');
    }
  } else {
    NO();
    return 0;
  }

  return 0;
}
