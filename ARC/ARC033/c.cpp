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

#include <atcoder/fenwicktree>
using namespace atcoder;

void solve(fenwick_tree<int> &ft)
{
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
        ft.add(x, 1);
    }
    if (t == 2)
    {
        // target までの和が、x 以上か？
        int ng = 0;
        int ok = 2e5 + 2;
        while (abs(ng - ok) > 1)
        {
            int mid = ng + ok;
            mid /= 2;
            if (ft.sum(1, mid+1) >= x)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        cout << ok << endl;
        ft.add(ok, -1);
    }
}

int main(void)
{
    int q;
    cin >> q;
    fenwick_tree<int> ft(2e5 + 1);
    while (q--)
    {
        solve(ft);
    }
}