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

void solve()
{
    vector<ll> col;
    rep(i, 3)
    {
        ll x;
        cin >> x;
        col.push_back(x);
    }
    ll inf = 2e9;
    ll ans = inf;
    auto check = [&](int i, int j)
    {
        if (abs(col[i] - col[j]) % 3 == 0)
        {
            ll ans = 0;
            ll flatten = max(col[i], col[j]) - abs(col[i] - col[j]) / 3;
            // debug(flatten);
            ans += abs(col[i] - col[j]) / 3 + flatten;
            return ans;
        }
        else
        {
            return inf;
        }
    };
    auto chmin = [](auto &a, auto b)
    { a = min(a, b); };
    chmin(ans, check(0, 1));
    chmin(ans, check(1, 2));
    chmin(ans, check(2, 0));
    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}