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

ll d(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

int main(void)
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll ok = -1;
    ll ng = 1e9 + 1;
    while (abs(ok - ng) > 1)
    {
        // rep1(target, 20)
        // { ここはstep2で消える
        // ll target = 9; ここはstep1で消える
        ll target = (ng + ok) / 2;
        ll price = a * target + b * d(target);
        // cout << target << " " << price << " " << (price <= x) << endl;　ここはstep2で消える
        if (price <= x)
        {
            ok = target;
        }
        else
        {
            ng = target;
        }
    }
    cout << ok << endl;
}