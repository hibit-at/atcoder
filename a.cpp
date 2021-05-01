#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;
using namespace std;

ll const mod = 1e9 + 7;

void plus_and_mod(ll &a, ll b, ll mod) {
  a += b;
  a %= mod;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "atcoder*";
  vector<vector<ll>> dp(n + 1, vector<ll>(8, 0));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 8) {
      plus_and_mod(dp[i + 1][j], dp[i][j], mod);
      if (s[i] == t[j]) {
        plus_and_mod(dp[i + 1][j + 1], dp[i][j], mod);
      }
    }
  }
  cout << dp[n][7] % mod << endl;
}