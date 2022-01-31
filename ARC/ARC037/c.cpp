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

ll n, k;
vector<ll> a, b;

ll func(ll mid)
{
    ll ans = 0;
    rep(i, n)
    {
        auto itr = upper_bound(all(b), mid / a[i]);
        ans += itr - b.begin();
    }
    return ans;
}

int main(void)
{
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    ll ng = -1;
    ll ok = 1e18 + 1;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ng + ok) / 2;
        ll res = func(mid);
        if (res >= k)
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