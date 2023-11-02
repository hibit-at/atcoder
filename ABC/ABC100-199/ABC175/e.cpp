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

int main(void)
{
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<ll>> maze(r, vector<ll>(c, 0));
    rep(i, k)
    {
        int rx, cx;
        ll v;
        cin >> rx >> cx >> v;
        rx--;
        cx--;
        maze[rx][cx] = v;
    }
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    // print_vector_vector(maze);
    vector<vector<vector<ll>>> dp(r, vector<vector<ll>>(c, vector<ll>(4, 0)));
    auto chmax = [](auto &a, auto b)
    { a = max(a, b); };
    dp[0][0][1] = maze[0][0];
    ll ans = 0;
    rep(i, r)
    {
        rep(j, c)
        {
            rep(k, 4)
            {
                ll now = dp[i][j][k];
                if (i + 1 < r)
                {
                    chmax(dp[i + 1][j][0], now);
                    chmax(dp[i + 1][j][1], now + maze[i + 1][j]);
                }
                if (j + 1 < c)
                {
                    chmax(dp[i][j + 1][k], now);
                    if (k < 3)
                    {
                        chmax(dp[i][j + 1][k + 1], now + maze[i][j + 1]);
                    }
                }
            }
        }
    }
    rep(k, 4)
    {
        rep(i, r)
        {
            rep(j, c)
            {
                chmax(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}