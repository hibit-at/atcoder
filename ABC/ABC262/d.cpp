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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    auto solve = [&](ll d)
    {
        // debug(d);
        vector<ll> b(n);
        rep(i, n)
        {
            b[i] = a[i] % d;
        }
        auto print_vector = [](auto v)
        {
            int size = v.size();
            rep(i, size)
            {
                if (i < size - 1)
                {
                    cout << v[i] << ' ';
                }
                else
                {
                    cout << v[i] << endl;
                }
            }
        };
        // print_vector(b);
        vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(n + 1, vector<mint>(d, 0)));
        dp[0][0][0] = 1;
        rep(i, n)
        {
            rep(j, n)
            {
                rep(k, d)
                {
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j + 1][(k + b[i]) % d] += dp[i][j][k];
                }
            }
        }
        return dp[n][d][0];
    };
    mint ans = 0;
    rep1(i, n)
    {
        ans += solve(i);
    }
    cout << ans.val() << endl;
}