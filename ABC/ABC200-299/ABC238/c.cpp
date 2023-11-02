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

const ll mod = 998244353;
const ll inv2 = (mod + 1) / 2;

ll sum(ll n)
{
    ll ans = n;
    ans %= mod;
    ans *= n+1;
    ans %= mod;
    ans *= inv2;
    ans %= mod;
    return ans;
}

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
    ll n;
    cin >> n;
    ll ans = 0;
    ll dig = 0;
    while(n > 0){
        ll lim = 9 * rpow(10,dig,1e18);
        ll range = min(n, lim);
        n -= range;
        // debug(range);
        range %= mod;
        ans += sum(range);
        // debug(ans);
        ans %= mod;
        dig ++;
    }
    cout << ans << endl;
}
