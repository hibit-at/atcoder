#include <algorithm>
#include <iostream>
#include <iomanip>
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
#include <stack>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  dp[0][0] = 1;
  rep(i, n)
  {
    rep(j, m+1)
    {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= 1000;
      int next = j + a[i];
      if (next <= m)
      {
        dp[i + 1][next] += dp[i][j];
        dp[i + 1][next] %= 1000;
      }
    }
  }
  cout << dp.back()[m] << endl; 
}