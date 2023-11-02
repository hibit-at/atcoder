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

ll calc_span(vector<bool> b)
{
    int m = b.size();
    int pos = 0;
    ll ans = 0;
    while (pos < m)
    {
        ll span = 0;
        while (b[pos] && pos < m)
        {
            pos++;
            span++;
        }
        ans += span * (span + 1) / 2;
        pos++;
    }
    return ans;
}

ll solve(vector<int> b, int x, int y)
{
    ll m = b.size();
    vector<bool> exclude_x(m);
    vector<bool> exclude_y(m);
    vector<bool> exclude_xy(m);
    rep(i, m)
    {
        exclude_x[i] = (b[i] != x);
        exclude_y[i] = (b[i] != y);
        exclude_xy[i] = (b[i] != x && b[i] != y);
    }
    ll ans = m * (m + 1) / 2;
    ans -= calc_span(exclude_x);
    ans -= calc_span(exclude_y);
    ans += calc_span(exclude_xy);
    return ans;
}

int main(void)
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll ans = 0;
    int pos = 0;
    while (pos < n)
    {
        vector<int> b;
        while ((y <= a[pos] && a[pos] <= x) && pos < n)
        {
            b.push_back(a[pos]);
            pos++;
        }
        ans += solve(b, x, y);
        pos++;
    }
    cout << ans << endl;
}