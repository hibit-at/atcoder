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
    set<int> x_pos;
    set<int> y_pos;
    rep(i, m)
    {
        if (b[i] == x)
        {
            x_pos.insert(i);
        }
        if (b[i] == y)
        {
            y_pos.insert(i);
        }
    }
    ll ans = 0;
    rep(i, m)
    {
        auto nearest_x = x_pos.lower_bound(i);
        auto nearest_y = y_pos.lower_bound(i);
        if (nearest_x == x_pos.end())
        {
            continue;
        }
        if (nearest_y == y_pos.end())
        {
            continue;
        }
        int both = max(*nearest_x, *nearest_y);
        ans += m - both;
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