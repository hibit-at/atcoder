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

#include <atcoder/segtree>
#include <atcoder/modint>
using namespace atcoder;
// using namespace atcoder;

using S = modint;

S gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

S lcm(S a, S b) { return a / gcd(a.val(), b.val()) * b; }

S op(S a, S b)
{
    return lcm(a, b);
}

S e()
{
    return 1;
}

int main(void)
{
    int n;
    cin >> n;
    // modint1000000007;
    modint::set_mod(1000000007);
    vector<S> v(n);
    segtree<S, op, e> seg(v);
    rep(i, n)
    {
        ll m;
        cin >> m;
        S tmp = 1;
        rep(j, m)
        {
            ll p, e;
            cin >> p >> e;
            while (e--)
            {
                // tmp *= p;
            }
        }
        debug(tmp.val());
    }
}