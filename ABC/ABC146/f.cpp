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

#include <atcoder/lazysegtree>
using namespace atcoder;

using S = long long;
using F = long long;

const S INF = 1e18;
const F ID = 1e18;

S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main(void)
{
    S n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<S> dp(n + 1, INF);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(dp);
    seg.set(n, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            continue;
        }
        dp[i] = seg.prod(i + 1, min(i + m + 1, n + 1)) + 1;
        seg.set(i, dp[i]);
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(dp);
    if (dp[0] >= INF)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int pos = 0;
    while (pos < n)
    {
        int val = dp[pos];
        int buf = 0;
        while (val <= dp[pos] && pos < n)
        {
            pos++;
            buf++;
        }
        ans.push_back(buf);
    }
    auto print_join = [](auto v)
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
    print_join(ans);
}