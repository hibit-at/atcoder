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
#include <atcoder/lazysegtree>
using namespace atcoder;
using mint = modint;

struct S
{
    mint value;
    int size;
};
using F = mint;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
int main()
{
    int n, p;
    cin >> n >> p;
    mint::set_mod(p);
    vector<lazy_segtree<S, op, e, F, mapping, composition, id>>
        dp(n, lazy_segtree<S, op, e, F, mapping, composition, id>(vector<S>(n + 1, {0, 1})));
    dp[0].set(0, {1, 1});
    rep(i, n - 1)
    {
        rep(j, n + 1)
        {
            int L = 1;
            int k = 1;
            int ways = 25;
            if (i == 0)
            {
                ways++;
            }
            while (j + L <= n && i + k + 1 < n)
            {
                int R = min(L * 10, n - j + 1);
                dp[i + k + 1].apply(j + L, j + R, dp[i].get(j).value * ways);
                L *= 10;
                k++;
            }
        }
    }
    // rep(i, n)
    // {
    //     rep(j, n + 1)
    //     {
    //         cout << dp[i].get(j).value.val() << ',';
    //     }
    //     cout << endl;
    // }
    mint ans = 0;
    rep(i, n)
    {
        ans += dp[i].get(n).value;
    }
    cout << ans.val() << endl;
}