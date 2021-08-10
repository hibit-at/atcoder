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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const int inf = 2e9;

void chmin(int &a, int b) { a = min(a, b); }

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<int> dp(n, inf);
  dp[0] = 0;
  rep1(now, n) {
    vector<int> from_steps(0);
    rep1(step, k) { from_steps.push_back(now - step); }
    for (int from : from_steps) {
      if (from < 0) {
        continue;
      }
      chmin(dp[now], dp[from] + abs(h[now] - h[from]));
    }
  }
  cout << dp.back() << endl;
}