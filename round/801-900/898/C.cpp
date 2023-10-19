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

int t;
string s[10];
int point[10] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> s[j];
    }

    int ans = 0;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (s[j][k] == 'X') {
          ans += min(point[j], point[k]);
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}