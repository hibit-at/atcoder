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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T>
void prll_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

template <typename S, typename T>
void prll_map(map<S, T> mp)
{
    for (auto p : mp)
    {
        cout << "key : " << p.first << ", value : " << p.second << endl;
    }
}

struct BIT
{
public:
    vector<ll> bit;
    ll N;

public:
    BIT(ll size)
    {
        N = size;
        bit.resize(N + 1);
    }

    // 一点更新です
    void add(ll a, ll w)
    {
        for (ll x = a; x <= N; x += x & -x)
            bit[x] += w;
    }

    // 1~Nまでの和を求める。
    ll sum(ll a)
    {
        ll ret = 0;
        for (ll x = a; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }
};

bool solve(ll n, ll target, vector<ll> a)
{
    rep(i, n)
    {
        if (a[i] > target)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = -1;
        }
    }
    // prll_vector(a);
    vector<ll> s(n + 1);
    rep(i, n)
    {
        s[i + 1] = a[i];
        s[i + 1] += s[i];
    }
    // prll_vector(s);
    BIT bit(2 * n + 2);
    ll inversion = 0;
    rep(j, n + 1)
    {
        ll offset = n + 1;
        // prll_vector(bit.bit);
        inversion += j - bit.sum(s[j] + offset);
        bit.add(s[j] + offset, 1);
    }
    ll m = n * (n + 1) / 2;
    debug(inversion);
    if (inversion >= m / 2)
    {
        // cout << "possible" << endl;
        return true;
    }
    else
    {
        // cout << "impossible" << endl;
        return false;
    }
}

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    // ll ok = 0;
    // ll ng = 1e9 + 1;
    // while (abs(ok - ng) > 1)
    rep1(target, 40)
    {
        // ll target = 10;
        // ll target = (ok + ng) / 2;
        if (solve(n, target, a))
        {
            cout << target << " possible" << endl;
            // ok = target;
        }
        else
        {
            cout << target << " impossible" << endl;
            // ng = target;
        }
    }
    // cout << ok << endl;
}