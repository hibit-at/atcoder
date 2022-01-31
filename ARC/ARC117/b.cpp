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

const ll mod = 1e9 + 7;

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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep1(i, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 1;
    rep(i, n)
    {
        ans *= a[i + 1] - a[i] + 1;
        ans %= mod;
    }
    cout << ans << endl;
}