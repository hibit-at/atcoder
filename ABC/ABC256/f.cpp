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
    int n, q;
    cin >> n >> q;
    vector<mint> a(n);
    vector<mint> B(n + 1);
    vector<mint> C(n + 1);
    vector<mint> D(n + 1);
    rep(i, n)
    {
        int x;
        cin >> x;
        a[i] = x;
        B[i + 1] = B[i] + a[i];
        C[i + 1] = C[i] + B[i + 1];
        D[i + 1] = D[i] + C[i + 1];
    }
    vector<vector<mint>> dp(5, vector<mint>(n + 1, 0));
    dp[0][0] = 1;
    rep(i, 4)
    {
        rep(j, n)
        {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][n] -= dp[i][j];
        }
        rep(j, n)
        {
            dp[i + 1][j + 1] += dp[i + 1][j];
        }
    }
    vector<pair<int, int>> vp;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, v;
            cin >> x >> v;
            x--;
            vp.push_back({x + 1, a[x].val() - v});
            a[x] = v;
        }
        if (type == 2)
        {
            int x;
            cin >> x;
            mint ans = D[x];
            for (auto p : vp)
            {
                int key = p.first;
                mint val = p.second;
                mint cont = dp[3][x - key];
                ans -= cont * val;
            }
            cout << ans.val() << endl;
        }
    }
}