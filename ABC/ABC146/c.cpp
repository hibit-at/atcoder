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

ll a, b, x;

ll d(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

ll func(ll mid)
{
    return a * mid + b * d(mid);
}

int main(void)
{
    cin >> a >> b >> x;
    ll ng = 1e9+1;
    ll ok = 0;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ng + ok) / 2;
        ll res = func(mid);
        if (res <= x)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}