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

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

double dist(double a, double b, double c, double d)
{
    double s = (a - c) * (a - c) + (b - d) * (b - d);
    return sqrt(s);
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<bool> light(n);
    rep(i, k)
    {
        cin >> a[i];
        a[i]--;
        light[a[i]] = true;
    }
    vector<double> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    double ng = 0;
    double ok = 1e8;
    while (abs(ng - ok) > 1e-8)
    {
        double mid = ng + ok;
        mid /= 2;
        auto solve = [&]()
        {
            rep(i, n)
            {
                int light_count = 0;
                rep(j, n)
                {
                    if (!light[j])
                    {
                        continue;
                    }
                    double d = dist(x[i], y[i], x[j], y[j]);
                    light_count += d <= mid;
                }
                if (light_count == 0)
                {
                    return false;
                }
            }
            return true;
        };
        if (solve())
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << setprecision(20) << ok << endl;
}