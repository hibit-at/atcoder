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

bool solve(ll r, ll b, ll target, ll x, ll y)
{
    r -= target;
    b -= target;
    if (r < 0 || b < 0)
    {
        // cout << "impossible" << endl;
        // return 0;
        return false;
    }
    x--;
    y--;
    if (r / x + b / y < target)
    {
        // cout << "impossible" << endl;
        return false;
    }
    // cout << "safe" << endl;
    return true;
}

int main(void)
{
    ll r, b;
    cin >> r >> b;
    ll x, y;
    cin >> x >> y;
    ll ok = -1;
    ll ng = 1e18 + 1;
    while (abs(ok - ng) > 1)
    // rep1(target, 20)
    {
        ll target = (ok + ng) / 2;
        // ll target = 2;
        // cout << target << " " << solve(r, b, target, x, y) << endl;
        if (solve(r, b, target, x, y))
        {
            ok = target;
        }
        else
        {
            ng = target;
        }
    }
    cout << ok << endl;
}