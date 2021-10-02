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
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

const int inf = 2e5;

void chmin(int &a, int b) { a = min(a, b); }

int inf_to_minus(int n)
{
  if (n == inf)
  {
    return -1;
  }
  return n;
}

int main(void)
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(x + 1, vector<int>(y + 1, inf)));
    dp[0][0][0] = 0;
    rep(i, n)
    {
        rep(tako, x + 1)
        {
            rep(tai, y + 1)
            {
                int add_tako = a[i];
                int add_tai = b[i];
                int next_tako = tako + add_tako;
                int next_tai = tai + add_tai;
                chmin(next_tako, x);
                chmin(next_tai, y);
                chmin(dp[i + 1][next_tako][next_tai], dp[i][tako][tai] + 1);
                chmin(dp[i + 1][tako][tai],dp[i][tako][tai]);
            }
        }
    }
    cout << inf_to_minus(dp[n][x][y]) << endl;
}