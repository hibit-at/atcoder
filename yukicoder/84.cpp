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

int main() {
  int k;
  cin >> k;
  vector<double> dp(2e5, 0);
  rep1(i, k) {
    int vi = i + 2e5;
    dp[vi] = 1;
    rep1(j, 6) { dp[vi] += dp[vi - j] * 1 / 6; }
  }
  cout << dp[2e5+k] << endl;
}