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
    ll n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    if (k == 1)
    {
        cout << "Infinity" << endl;
        return 0;
    }
    map<pair<double, double>, bool> dp;
    ll ans = 0;
    rep(i, n)
    {
        for (ll j = i + 1; j < n; j++)
        {
            if (x[i] == x[j] && y[i] == y[j])
            {
                continue;
            }
            ll xdif = x[j] - x[i];
            ll ydif = y[j] - y[i];
            double intercept = 0;
            if (xdif == 0)
            {
                ydif = 1;
                intercept = x[i];
            }
            else if (ydif == 0)
            {
                xdif = 1;
                intercept = y[i];
            }
            else
            {
            }
            // debug(xdif);
            // debug(ydif);
            if (dp[{{xdif, ydif}, intercept}])
            {
                continue;
            }
            ll count = 0;
            rep(p, n)
            {
                bool criteria = xdif * (y[p] - y[i]) == ydif * (x[p] - x[i]);
                if (xdif == 0)
                {
                    criteria = (x[p] == x[i]);
                }
                if (ydif == 0)
                {
                    criteria = (y[p] == y[i]);
                }
                if (criteria)
                {
                    count++;
                }
            }
            if (count >= k)
            {
                debug(x[i]);
                debug(y[i]);
                debug(x[j]);
                debug(y[j]);
                debug("ok!");
                ans++;
            }
            dp[{{xdif, ydif}, intercept}] = true;
        }
    }
    cout << ans << endl;
}