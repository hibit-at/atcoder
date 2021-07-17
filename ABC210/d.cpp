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

void print_vector_vector(vector<vector<ll>> vv) {
  for (vector<ll> v : vv) {
    for (ll i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

void debug_inf(ll n) {
  if (n >= inf) {
    cout << "#,";
  } else {
    cout << n << ",";
  }
}


int main() {
  ll h, w, c;
  cin >> h >> w >> c;
  vector<vector<ll>> maze(h, vector<ll>(w));
  rep(i, h) {
    rep(j, w) { cin >> maze[i][j]; }
  }
  vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(3)));
  // 0 ... 始点
  // 1 ... スルー
  // 2 ... そこを終点とする
  rep(i, h) {
    rep(j, w) { dp[i][j][0] = maze[i][j]; }
  }
  dp[0][0][1] = inf;
  dp[0][0][2] = inf;
  //まずスルーの処理
  rep(i, h) {
    rep(j, w) {
      rep(k, 2) {
        if (i < h - 1) {
          dp[i + 1][j][1] = min(dp[i][j][0], dp[i][j][1]) + c;
        }
        if (j < w - 1) {
          dp[i][j + 1][1] = min(dp[i][j][0], dp[i][j][1]) + c;
        }
        dp[i][j][2] = dp[i][j][1] + maze[i][j];
      }
    }
  }
  // rep(i, h) {
  //   rep(j, w) { debug_inf(dp[i][j][1]); }
  //   cout << endl;
  // }
  // rep(i, h) {
  //   rep(j, w) { debug_inf(dp[i][j][2]); }
  //   cout << endl;
  // }
  ll ans = inf;
  rep(i, h) {
    rep(j, w) { ans = min(ans, dp[i][j][2]); }
  }
  cout << ans << endl;
}