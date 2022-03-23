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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    ll sum = 0;
    reverse(all(a));
    reverse(all(b));
    ll ans = 0;
    rep(i, n)
    {
        ll diff = a[i] + sum;
        diff %= b[i];
        if (diff == 0)
        {
            continue;
        }
        if (diff < 0)
        {
            diff += b[i];
            diff %= b[i];
        }
        ans += b[i] - diff;
        // debug(b[i] - diff);
        sum += b[i] - diff;
    }
    cout << ans << endl;
}