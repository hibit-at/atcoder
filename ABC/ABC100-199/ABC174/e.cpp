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

bool solve(double mid)
{
    return true;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    int ng = 0;
    int ok = 1e9;
    while (abs(ng - ok) > 1)
    {
        int mid = ok + ng;
        mid /= 2;
        // debug(mid);
        int need = 0;
        rep(i, n)
        {
            need += (a[i] + mid - 1) / mid - 1;
        }
        // debug(need);
        if (need <= k)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}