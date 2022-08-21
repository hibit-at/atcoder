
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
    ll n, d;
    cin >> n >> d;
    vector<ll> lower(n, -1e18), upper(n, 1e18);
    auto chmax = [](auto &a, auto b)
    { a = max(a, b); };
    auto chmin = [](auto &a, auto b)
    { a = min(a, b); };
    vector<ll> p(n), q(n);
    cin >> p >> q;
    rep(i, n)
    {
        debug(i);
        rep(state, 1 << n)
        {
            ll rot_p = 0;
            rep(j, n)
            {
                if (j == 0)
                {
                    rot_p += p[j];
                }
                else
                {
                    if (state >> j & 1)
                    {
                        rot_p += p[j];
                    }
                    else
                    {
                        rot_p -= p[j];
                    }
                }
            }
            debug(rot_p);
            chmax(lower[i], rot_p - d);
            chmin(upper[i], rot_p + d);
            ll rot_q = 0;
            rep(j, n)
            {
                if (j == 0)
                {
                    rot_q += q[j];
                }
                else
                {
                    if (state >> j & 1)
                    {
                        rot_q += q[j];
                    }
                    else
                    {
                        rot_q -= q[j];
                    }
                }
            }
            debug(rot_q);
            chmax(lower[i], rot_q - d);
            chmin(lower[i], rot_q + d);
        }
    }
    auto print_vector = [](auto v)
    {
        int size = v.size();
        int cnt = 1;
        for (auto i : v)
        {
            cout << i;
            if (cnt < size)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
            cnt++;
        }
    };
    print_vector(lower);
    print_vector(upper);
    mint ans = 1;
    rep(i, n)
    {
        if (lower >= upper)
        {
            cout << 0 << endl;
            return 0;
        }
        ans *= upper[i] - lower[i] + 1;
    }
    cout << ans.val() << endl;
}