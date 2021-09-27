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
    vector<ll> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    sort(all(x));
    sort(all(y));
    ll mid_x;
    ll mid_y;
    if (n % 2 == 0)
    {
        mid_x = (x[n / 2 - 1] + x[n / 2]) / 2;
        mid_y = (y[n / 2 - 1] + y[n / 2]) / 2;
    }
    else
    {
        mid_x = x[n / 2];
        mid_y = y[n / 2];
    }
    ll ans = 0;
    rep(i, n)
    {
        ans += abs(x[i] - mid_x);
        ans += abs(y[i] - mid_y);
    }
    cout << ans << endl;
}