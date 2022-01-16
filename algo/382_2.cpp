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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 0;
    rep(i, n)
    {
        ll ng = -1;
        ll ok = n;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            ll crt = a[i] + a[mid];
            if (crt >= k)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        ans += n - ok;
    }
    cout << ans << endl;
}