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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    int b_max = *max_element(all(b));
    vector<vector<mint>> dp(n + 1, vector<mint>(b_max + 2));
    dp[0][0] = 1;
    rep(i, n + 1)
    {
        if (i > 0)
        {
            rep(j, b_max)
            {
                dp[i][j + 1] += dp[i][j];
            }
        }
        if (i < n)
        {
            rep(j, b_max + 1)
            {
                int start = max(a[i], j);
                int end = b[i];
                if (end < start)
                {
                    continue;
                }
                dp[i + 1][start] += dp[i][j];
                dp[i + 1][end + 1] -= dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(i, b_max + 1)
    {
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
}