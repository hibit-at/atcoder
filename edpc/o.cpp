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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<mint>> dp(n + 1, vector<mint>(1 << n, 0));
    dp[0][0] = 1;
    rep(man, n)
    {
        rep(state, 1 << n)
        {
            if (__builtin_popcount(state) != man)
            {
                continue;
            }
            rep(woman, n)
            {
                bool bit = (state >> woman) & 1;
                if (bit)
                {
                    continue;
                }
                if (!a[man][woman])
                {
                    continue;
                }
                int next_state = state | (1 << woman);
                dp[man + 1][next_state] += dp[man][state];
            }
        }
    }
    cout << dp[n][(1 << n) - 1].val() << endl;
}