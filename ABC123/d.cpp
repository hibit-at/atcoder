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

bool func(vector<ll> &a, vector<ll> &d, ll x, ll mid, ll target)
{
    ll tmp = 0;
    rep(i, x)
    {
        auto itr = upper_bound(all(d), mid - a[i]);
        tmp += d.end() - itr;
    }
    return tmp <= target;
}

int main(void)
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x)
    {
        cin >> a[i];
    }
    rep(i, y)
    {
        cin >> b[i];
    }
    rep(i, z)
    {
        cin >> c[i];
    }
    // sum of B,C
    vector<ll> d;
    rep(i, y)
    {
        rep(j, z)
        {
            d.push_back(b[i] + c[j]);
        }
    }
    sort(all(d));
    // nibutan
    rep(target, k)
    {
        ll ng = 0;
        ll ok = 1e18;
        while (abs(ng - ok) > 1)
        {
            ll mid = (ng + ok) / 2;
            // midより上の合計の組み合わせはtarget以下か？
            if (func(a, d, x, mid, target))
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
}