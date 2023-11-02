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

double dist(double x1, double y1, double x2, double y2)
{
    double ans = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    return sqrt(ans);
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            chmax(ans, dist(x[i], y[i], x[j], y[j]));
        }
    }
    cout << setprecision(20) << ans << endl;
}