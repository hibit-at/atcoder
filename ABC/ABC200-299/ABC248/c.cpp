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
using mint = modint998244353;

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));
    dp[0][0] = 1;
    rep(i, n)
    {
        rep(j, k)
        {
            rep1(plus, m)
            {
                if (j + plus <= k)
                {
                    dp[i + 1][j + plus] += dp[i][j];
                }
            }
        }
    }
    mint ans = 0;
    rep(i, k + 1)
    {
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
}