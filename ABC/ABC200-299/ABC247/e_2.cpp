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
    ll ans = 0;
    int L = 0;
    int R = 0;
    int countX = 0;
    int countY = 0;
    int m = b.size();
    while (L < m)
    {
        while ((countX == 0 || countY == 0) && R < m)
        {
            countX += (b[R] == x);
            countY += (b[R] == y);
            R++;
        }
        if (countX > 0 && countY > 0)
        {
            ans += m - R + 1;
        }
        countX -= (b[L] == x);
        countY -= (b[L] == y);
        L++;
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