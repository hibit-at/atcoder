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

int n, u_d, u_h;
vector<double> d, h;

bool func(double mid)
{
    double slope = u_h - mid;
    slope /= u_d;
    rep(i, n)
    {
        if (h[i] >= slope * d[i] + mid)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    cin >> n >> u_d >> u_h;
    d.resize(n);
    h.resize(n);
    rep(i, n)
    {
        cin >> d[i] >> h[i];
    }
    double ng = 0;
    double ok = u_h;
    while (abs(ng - ok) > 1e-10)
    {
        double mid = (ng + ok) / 2;
        if (func(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << setprecision(29) << ok << endl;
}