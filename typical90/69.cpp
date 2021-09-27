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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

const ll mod = pow(10, 9) + 7;

ll rpow(ll a, ll r, ll mod)
{
    if (r == 0)
        return 1;
    ll ans = rpow(a, r / 2, mod);
    ans *= ans;
    ans %= mod;
    if (r % 2 == 1)
        ans *= a;
    ans %= mod;
    return ans;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    ll ans = k;
    if (n == 1)
    {
        cout << ans << endl;
        return 0;
    }
    ans *= k - 1;
    ans %= mod;
    if (n == 2)
    {
        cout << ans << endl;
        return 0;
    }
    ans *= rpow(k - 2, n - 2, mod);
    ans %= mod;
    cout << ans << endl;
}