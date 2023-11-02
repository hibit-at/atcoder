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

#include <atcoder/segtree>
using namespace atcoder;

int op(int a, int b) { return a + b; }

int e() { return 0; }

int target;

bool f(int v) { return v <= target; }

ll solve(vector<int> b, int x, int y)
{
    int m = b.size();
    segtree<int, op, e> seg_x(m), seg_y(m);
    rep(i, m)
    {
        seg_x.set(i, b[i] == x);
        seg_y.set(i, b[i] == y);
    }
    ll ans = 0;
    rep(i, m)
    {
        target = seg_x.prod(0, i);
        int where_x = seg_x.max_right<f>(0);
        target = seg_y.prod(0, i);
        int where_y = seg_y.max_right<f>(0);
        int both = max(where_x, where_y);
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