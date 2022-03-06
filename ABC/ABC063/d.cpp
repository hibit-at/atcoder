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

bool solve(ll target, vector<ll> h, ll n, ll a, ll b)
{
    rep(i, n)
    {
        h[i] -= b * target;
    }
    a -= b;
    ll count = 0;
    rep(i, n)
    {
        if (h[i] <= 0)
        {
            continue;
        }
        count += (h[i] + a - 1) / a;
    }
    if (count <= target)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }
    ll ng = -1;
    ll ok = 1e9 + 1;
    while (abs(ng - ok) > 1)
    // rep(target, 10)
    {
        ll target = (ok + ng) / 2;
        if (solve(target, h, n, a, b))
        {
            // cout << target << " ok" << endl;
            ok = target;
        }
        else
        {
            // cout << targt << " ng" << endl;
            ng = target;
        }
    }
    cout << ok << endl;
}