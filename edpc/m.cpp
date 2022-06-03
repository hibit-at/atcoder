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
using mint = modint1000000007;

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    // if (k == 0)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }
    vector<vector<mint>> dp(n + 1, vector<mint>(k + 2, 0));
    dp[0][0] = 1;
    rep(i, n + 1)
    {
        if (i > 0)
        {
            rep(j, k + 1)
            {
                dp[i][j + 1] += dp[i][j];
            }
        }
        if (i < n)
        {
            rep(j, k+1)
            {
                int limit = min(j + a[i] + 1, k+1);
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][limit] -= dp[i][j];
            }
        }
    }
    // rep(i, n + 1)
    // {
    //     rep(j, k + 1)
    //     {
    //         cout << dp[i][j].val() << ',';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][k].val() << endl;
}