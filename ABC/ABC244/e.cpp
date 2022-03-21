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
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    vector<vector<int>> to(n + 1, vector<int>());
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(k + 1, vector<mint>(2)));
    dp[s][0][0] = 1;
    rep(j, k)
    {
        rep(OddX, 2)
        {
            rep1(from, n)
            {
                for (int next : to[from])
                {
                    if (next == x)
                    {
                        dp[next][j + 1][(OddX + 1) % 2] += dp[from][j][OddX];
                    }
                    else
                    {
                        dp[next][j + 1][OddX] += dp[from][j][OddX];
                    }
                }
            }
        }
    }
    // debug("Even");
    // rep(j, k + 1)
    // {
    //     debug(j);
    //     rep1(i, n)
    //     {
    //         cout << dp[i][j][0].val() << ',';
    //     }
    //     cout << endl;
    // }
    // debug("Odd");
    // rep(j, k + 1)
    // {
    //     debug(j);
    //     rep1(i, n)
    //     {
    //         cout << dp[i][j][1].val() << ',';
    //     }
    //     cout << endl;
    // }
    cout << dp[t][k][0].val() << endl;
}