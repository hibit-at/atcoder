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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

ll lunlun(ll mid)
{
    vector<ll> digits(18);
    rep(i, 18)
    {
        int j = 17 - i;
        digits[j] = mid % 10;
        mid /= 10;
    }
    print_vector(digits);
    vector<vector<vector<ll>>> dp(19, vector<vector<ll>>(2, vector<ll>(10, 0)));
    return 10;
}

bool solve(ll mid, int k)
{
    if (lunlun(mid) >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    ll k;
    cin >> k;
    ll ng = -1;
    ll ok = 1e18;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (solve(mid, k))
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