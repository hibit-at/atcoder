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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> from(h, vector<int>(w));
    vector<vector<int>> to(h, vector<int>(w));
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> from[i][j];
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> to[i][j];
        }
    }
    ll ans = 0;
    rep(i, h - 1)
    {
        rep(j, w - 1)
        {
            ll target = to[i][j] - from[i][j];
            from[i][j] += target;
            from[i + 1][j] += target;
            from[i][j + 1] += target;
            from[i + 1][j + 1] += target;
            ans += abs(target);
        }
    }
    rep(i, h)
    {
        if (from[i][w - 1] != to[i][w - 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(j, w)
    {
        if (from[h - 1][j] != to[h - 1][j])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}