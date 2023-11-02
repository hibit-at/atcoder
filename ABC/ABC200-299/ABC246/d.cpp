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

ll criteria(ll a, ll b)
{
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main(void)
{
    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1e18;
    for (ll a = 0; a <= 1e6; a++)
    {
        // debug(a);
        ll ng = a - 1;
        ll ok = 1e6 + 1;
        while (abs(ng - ok) > 1)
        {
            ll b = ng + ok;
            b /= 2;
            if (a == 0 && b == 0)
            {
                ng = b;
                continue;
            }
            if (criteria(a,b) >= n)
            {
                ok = b;
            }
            else
            {
                ng = b;
            }
        }
        // cout << ok << endl;
        // debug(criteria(a,ok));
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(ans, criteria(a,ok));
    }
    cout << ans << endl;
}