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

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

const ll mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string ckd = "chokudai";
  vector<vector<ll>> dp(n + 1, vector<ll>(9, 0));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 9) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= mod; 
      if (j < 8 && s[i] == ckd[j]) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= mod;
      }
    }
  }
  // print_vector_vector(dp);
  cout << dp[n][8] << endl;
}