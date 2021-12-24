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

int func(double mid, vector<double> L)
{
    int ans = 0;
    for (double _L : L)
    {
        int pre_ans = _L / mid;
        ans += pre_ans;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> L(n);
    rep(i, n)
    {
        cin >> L[i];
    }
    double ok = 1e-8;
    double ng = 1e5;
    while (abs(ok - ng) > 1e-8)
    {
        double mid = (ok + ng) / 2;
        int res = func(mid, L);
        if (res >= k)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << setprecision(10) << ok << endl;
}