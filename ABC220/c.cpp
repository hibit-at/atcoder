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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll x;
    cin >> x;
    ll sum = 0;
    rep(i, n)
    {
        sum += a[i];
        if (sum > x)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    // debug(sum);
    ll ans = (x / sum) * n;
    // debug(ans);
    x %= sum;
    // debug(x);
    rep(i, n)
    {
        x -= a[i];
        ans++;
        if (x < 0)
        {
            cout << ans << endl;
            return 0;
        }
    }
}