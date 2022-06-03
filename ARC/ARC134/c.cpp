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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

ll mod = 998244353;

vector<ll> inv;

ll comb(ll n, ll k)
{
    ll ans = 1;
    while (k > 0)
    {
        ans *= n;
        ans %= mod;
        ans *= inv[k];
        ans %= mod;
        n--;
        k--;
    }
    return ans;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    inv.resize(k + 1, 1);
    rep(i, k + 1)
    {
        if (i < 2)
        {
            continue;
        }
        inv[i] = mint(i).inv().val();
    }
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    a[0] -= k;
    if (a[0] < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll count_1 = a[0];
    ll count_not_1 = accumulate(a.begin() + 1, a.end(), 0LL);
    if (count_1 < count_not_1)
    {
        cout << 0 << endl;
        return 0;
    }
    a[0] -= count_not_1;
    mint ans = 1;
    rep(i, n)
    {
        ans *= comb(a[i] + k - 1, k - 1);
    }
    cout << ans.val() << endl;
}