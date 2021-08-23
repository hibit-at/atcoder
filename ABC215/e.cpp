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

int next_kind(char c) { return c - 'A'; }

string binary_expression(int n, int d) {
  string ans = "";
  rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
  return ans;
}

const ll mod = 998244353;

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<vector<ll>>> dp(n + 1,
                                vector<vector<ll>>(1 << 10, vector<ll>(11)));
  dp[0][0][10] = 1;
  rep(i, n) {
    int next = s[i] - 'A';
    rep(state, 1 << 10) {
      rep(last, 11) {
        if (dp[i][state][last] == 0) {
          continue;
        }
        dp[i + 1][state][last] += dp[i][state][last];
        dp[i + 1][state][last] %= mod;
        int next = s[i] - 'A';
        if (state & (1 << next) && last != next) {
          continue;
        }
        int next_state = state | (1 << next);
        dp[i + 1][next_state][next] += dp[i][state][last];
        dp[i + 1][next_state][next] %= mod;
      }
    }
  }
  ll ans = 0;
  rep(state, 1 << 10) {
    rep(last, 10) {
      if (dp[n][state][last] == 0) {
        continue;
      }
      ans += dp[n][state][last];
      ans %= mod;
    }
  }
  cout << ans << endl;
}