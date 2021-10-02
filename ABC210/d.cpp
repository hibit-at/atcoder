#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const ll inf = 1e18;

void chmin(ll &a, ll b) { a = min(a, b); }

int main() {
  ll h, w, c;
  cin >> h >> w >> c;
  vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(h, vector<ll>(w, inf)));
  rep(i, h) {
    rep(j, w) { cin >> dp[0][i][j]; }
  }
  rep(i, h) {
    rep(j, w) {
      ll route = min(dp[0][i][j], dp[1][i][j]) + c;
      if (i < h - 1) {
        chmin(dp[1][i + 1][j], route);
      }
      if (j < w - 1) {
        chmin(dp[1][i][j + 1], route);
      }
    }
  }
  rep(i, h) { reverse(all(dp[0][i])); }
  rep(i, h) {
    rep(j, w) {
      ll route = min(dp[0][i][j], dp[2][i][j]) + c;
      if (i < h - 1) {
        chmin(dp[2][i + 1][j], route);
      }
      if (j < w - 1) {
        chmin(dp[2][i][j + 1], route);
      }
    }
  }
  rep(i, h) { reverse(all(dp[1][i])); }
  ll ans = inf;
  rep(i, h) {
    rep(j, w) {
      ll cost = dp[0][i][j] + min(dp[1][i][j], dp[2][i][j]);
      chmin(ans, cost);
    }
  }
  cout << ans << endl;
}