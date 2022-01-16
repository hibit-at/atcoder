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
const int inf = 1e9;

double dist(pair<int, int> prev, pair<int, int> next)
{
    double xdiff = double(prev.first - next.first);
    double ydiff = double(prev.second - next.second);
    return sqrt(xdiff * xdiff + ydiff * ydiff);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    vector<bool> seen(n);
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }
    double ans = 0;
    rep(prev, n)
    {
        if (seen[prev])
        {
            continue;
        }
        seen[prev] = true;
        double min_dist = 1e9;
        int next = -1;
        rep(tmp_next, n)
        {
            if (seen[tmp_next])
            {
                continue;
            }
            double now_dist = dist(vp[prev], vp[tmp_next]);
            if (now_dist < min_dist)
            {
                min_dist = now_dist;
                next = tmp_next;
            }
        }
        if (next == -1)
        {
            ans += dist(vp[prev],vp[0]);
            break;
        }
        ans += min_dist;
        prev = next - 1;
    }
    cout << setprecision(10) << ans << endl;
}