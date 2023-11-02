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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint;

int main()
{
    int n, p;
    cin >> n >> p;
    mint::set_mod(p);
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 2));
    dp[0][0] = 1;
    rep(i, n + 1)
    {
        if (i > 0)
        {
            rep(j, n + 1)
            {
                dp[i][j + 1] += dp[i][j];
            }
        }
        rep(j, n + 1)
        {
            int L = 1;
            int k = 1;
            int ways = 25;
            if (i == 0)
            {
                ways++;
            }
            while (j + L <= n && i + k + 1 <= n)
            {
                int R = min(L * 10, n - j + 1);
                dp[i + k + 1][j + L] += dp[i][j] * ways;
                dp[i + k + 1][j + R] -= dp[i][j] * ways;
                L *= 10;
                k++;
            }
        }
    }
    mint ans = 0;
    rep(i, n)
    {
        ans += dp[i][n];
    }
    cout << ans.val() << endl;
}