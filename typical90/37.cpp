#include <algorithm>
#include <iostream>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

#include <atcoder/lazysegtree>
using namespace atcoder;

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main()
{
    int w, n;
    cin >> w >> n;
    vector<S> init(w + 1);
    using lazy = lazy_segtree<S, op, e, F, mapping, composition, id>;
    vector<int> L(n), R(n), v(n);
    rep(i, n)
    {
        cin >> L[i] >> R[i] >> v[i];
    }
    vector<lazy> dp(n + 1, lazy(init));
    rep(i, n)
    {
        rep(j, w + 1)
        {
            // int left = min(j + L[i], w + 1);
            // int right = min(j + R[i], w + 1);
            int left = j + L[i];
            int right = j + R[i];
            auto chmin = [](auto &a, auto b)
            { a = min(a, b); };
            chmin(left, w + 1);
            chmin(right, w + 1);
            dp[i + 1].apply(left, right, dp[i].get(j) + v[i]);
        }
    }
    rep(i, n + 1)
    {
        rep(j, w + 1)
        {
            cout << dp[i].get(j) << ",";
        }
        cout << endl;
    }
}