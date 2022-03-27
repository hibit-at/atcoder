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

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), c(n + m + 1);
    rep(i, n + 1)
    {
        cin >> a[i];
    }
    rep(i, n + m + 1)
    {
        cin >> c[i];
    }
    vector<ll> ans(0);
    reverse(all(a));
    reverse(all(c));
    rep(i, m + 1)
    {
        ll factor = c[i] / a[0];
        rep(j, n + 1)
        {
            c[i + j] -= a[j] * factor;
        }
        ans.push_back(factor);
    }
    reverse(all(ans));
    rep(i, m + 1)
    {
        cout << ans[i];
        if (i < m)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
    }
}