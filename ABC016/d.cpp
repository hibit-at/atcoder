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

typedef struct Point_Coordinates
{
    double x, y;
} point;

bool judge(point &a, point &b, point &c, point &d)
{
    double s, t;
    s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
    t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
    if (s * t > 0)
        return false;

    s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
    t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
    if (s * t > 0)
        return false;
    return true;
}

int main(void)
{
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    point chop1;
    chop1.x = ax;
    chop1.y = ay;
    point chop2;
    chop2.x = bx;
    chop2.y = by;
    int n;
    cin >> n;
    vector<point> vp;
    rep(i, n)
    {
        double x, y;
        cin >> x >> y;
        point tmp;
        tmp.x = x;
        tmp.y = y;
        vp.push_back(tmp);
    }
    int cnt = 0;
    rep(i, n)
    {
        point from;
        point to;
        if (i < n - 1)
        {
            from = vp[i];
            to = vp[i + 1];
        }
        else
        {
            from = vp[i];
            to = vp[0];
        }
        cnt += judge(chop1, chop2, from, to);
    }
    cout << 1 + cnt / 2 << endl;
}