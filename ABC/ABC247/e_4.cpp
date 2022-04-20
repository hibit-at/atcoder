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

ll solve(vector<int> b, int x, int y)
{
    int m = b.size();
    vector<int> sum_x(m + 1), sum_y(m + 1);
    rep(i, m)
    {
        sum_x[i + 1] = (b[i] == x) + sum_x[i];
        sum_y[i + 1] = (b[i] == y) + sum_y[i];
    }
    ll ans = 0;
    rep(i, m)
    {
        auto nearest_x = lower_bound(all(sum_x), sum_x[i] + 1);
        auto nearest_y = lower_bound(all(sum_y), sum_y[i] + 1);
        int where_x = nearest_x - sum_x.begin();
        int where_y = nearest_y - sum_y.begin();
        int both = max(where_x, where_y);
        ans += m - both + 1;
    }
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