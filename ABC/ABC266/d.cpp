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
    int n;
    cin >> n;
    vector<vector<ll>> snuke(1e5 + 1, vector<ll>(5));
    rep(i, n)
    {
        int t, x, ll;
        cin >> t >> x >> ll;
        snuke[t][x] = ll;
    }
    vector<vector<ll>> dp(1e5 + 1, vector<ll>(5, -1));
    dp[0][0] = snuke[0][0];
    vector<int> dx = {-1, 0, 1};
    rep(i, 1e5)
    {
        rep(j, 5)
        {
            if (dp[i][j] == -1)
            {
                continue;
            }
            rep(k, 3)
            {
                int nj = j + dx[k];
                if (nj < 0 || 5 <= nj)
                {
                    continue;
                }
                // debug(nj);
                auto chmax = [](auto &a, auto b)
                { a = max(a, b); };
                chmax(dp[i + 1][nj], dp[i][j] + snuke[i + 1][nj]);
            }
        }
    }
    ll ans = 0;
    rep(j, 5)
    {
        auto chmax = [](auto &a, auto b)
        { a = max(a, b); };
        chmax(ans, dp[1e5][j]);
    }
    cout << ans << endl;
}