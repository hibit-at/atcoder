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

const ll inf = 1e18;

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

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--)
    {
        ll t, k;
        cin >> t >> k;
        k--;
        ll loop = t;
        ll border = 1;
        while (border < 1e18 && loop > 0)
        {
            border *= 2;
            loop--;
        }
        ll org_pos = k / border;
        ll after_pos = k % border;
        ll ans = s[org_pos] - 'A' + t;
        ll bit = __builtin_popcountll(after_pos);
        ans += bit;
        ans %= 3;
        cout << "ABC"[ans] << endl;
    }
}
