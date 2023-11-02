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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<int> r(h), c(w);
    cin >> r >> c;
    vector<vector<int>> a(h, vector<int>(w, 0));
    cin >> a;
    ll inf = 1e18;
    using VI = vector<ll>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    using VVVVI = vector<VVVI>;
    using VVVVVI = vector<VVVVI>;
    VVVVI dp(h, VVVI(w, VVI(2, VI(2, inf))));
    dp[0][0][0][0] = 0;
    dp[0][0][1][0] = r[0];
    dp[0][0][0][1] = c[0];
    rep(i, h)
    {
        rep(j, w)
        {
            rep(swap_h, 2)
            {
                rep(swap_w, 2)
                {
                    auto chmin = [](auto &a, auto b)
                    { a = min(a, b); };
                    if (i + 1 < h)
                    {
                        bool isSwap = a[i + 1][j] ^ a[i][j];
                        chmin(dp[i + 1][j][swap_h ^ 1 ^ isSwap][swap_w], dp[i][j][swap_h][swap_w] + r[i+1]);
                        chmin(dp[i + 1][j][swap_h ^ isSwap][swap_w], dp[i][j][swap_h][swap_w]);
                    }
                    if (j + 1 < w)
                    {
                        bool isSwap = a[i][j + 1] ^ a[i][j];
                        chmin(dp[i][j + 1][swap_h][swap_w ^ 1 ^ isSwap], dp[i][j][swap_h][swap_w] + c[j+1]);
                        chmin(dp[i][j + 1][swap_h][swap_w ^ isSwap], dp[i][j][swap_h][swap_w]);
                    }
                }
            }
        }
    }
    ll ans = 1e18;
    rep(swap_h, 2)
    {
        rep(swap_w, 2)
        {
            auto chmin = [](auto &a, auto b)
            { a = min(a, b); };
            chmin(ans, dp[h - 1][w - 1][swap_h][swap_w]);
        }
    }
    cout << ans << endl;
    rep(i, h)
    {
        rep(j, w)
        {
            ll tmp = 1e18;
            rep(swap_h, 2)
            {
                rep(swap_w, 2)
                {
                    auto chmin = [](auto &a, auto b)
                    { a = min(a, b); };
                    chmin(tmp, dp[i][j][swap_h][swap_w]);
                }
            }
            cout << tmp << ",";
        }
        cout << endl;
    }
}