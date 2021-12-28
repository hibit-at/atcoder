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
    vector<int> a(n), b(n), c(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    rep(i, n)
    {
        cin >> c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0;
    for (ll i : b)
    {
        auto itr_a = lower_bound(all(a), i);
        ll where_a = itr_a - a.begin();
        auto itr_c = upper_bound(all(c), i);
        ll where_c = c.end() - itr_c;
        ans += where_a * where_c;
    }
    cout << ans << endl;
}