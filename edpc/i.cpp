#include <algorithm>
#include <iomanip>
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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const ll mod = 1e9 + 7;

void print_vector_vector(vector<vector<double>> vv) {
  for (vector<double> v : vv) {
    for (double i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<double> p(n);
  rep(i, n) { cin >> p[i]; }
  vector<vector<double>> dp;
  dp.resize(n + 1);
  rep(i, n + 1) { dp[i].resize(n + 1, 0); }
  dp[0][0] = 1;
  rep(total, n) {
    rep(top, n) {
      dp[total + 1][top + 1] += dp[total][top] * p[total];
      dp[total + 1][top] += dp[total][top] * (1 - p[total]);
    }
  }
//   print_vector_vector(dp);
  double ans = 1;
  rep(i, (n + 1) / 2) { ans -= dp[n][i]; }
  cout << setprecision(20) << ans << endl;
}