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
const ll mod = (ll)1e5;

ll solve_y(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

ll solve(ll n)
{
    ll y = solve_y(n);
    n = (n + y) % mod;
    return n;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    ll loop = min(k, mod);
    vector<bool> seen(mod, false);
    if (k < mod)
    {
        rep(i, k)
        {
            n = solve(n);
        }
        cout << n << endl;
        return 0;
    }
    ll tmp = n;
    int loop_end = -1;
    ll end_num = -1;
    rep(i, mod)
    {
        // debug(tmp);
        if (seen[tmp])
        {
            loop_end = i;
            end_num = tmp;
            break;
        }
        seen[tmp] = true;
        tmp = solve(tmp);
    }
    // debug(loop_end);
    // debug(end_num);
    tmp = n;
    int loop_start = -1;
    rep(i, mod)
    {
        if (tmp == end_num)
        {
            loop_start = i;
            break;
        }
        tmp = solve(tmp);
    }
    // debug(loop_start);
    ll interval = loop_end - loop_start;
    // debug(interval);
    k -= loop_start;
    k %= interval;
    // debug(k);
    n = end_num;
    rep(i, k)
    {
        // debug(n);
        n = solve(n);
    }
    cout << n << endl;
}