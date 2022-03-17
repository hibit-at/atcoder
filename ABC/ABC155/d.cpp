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
vector<T> slice(vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    vector<T> vec(first, last);
    return vec;
}

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

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    for (ll target = -5; target < 5; target++)
    {
        debug(target);
        // ll target = -7;
        ll count = 0;
        rep(i, n - 1)
        {
            // debug(i);
            if (a[i] < 0)
            {
                auto upper = upper_bound(all(a), target / a[i]);
                debug(target / a[i]);
                ll pos = upper - a.begin();
                debug(pos);
                count += min(pos, n - pos);
                // debug(n - pos);
            }
            else if (a[i] == 0)
            {
                int pos;
                if (target >= 0)
                {
                    pos = n;
                }
                else
                {
                    pos = 0;
                }
                debug(pos);
                count += max(0, pos - i - 1);
            }
            else
            {
                auto upper = upper_bound(all(a), target / a[i]);
                int pos = upper - a.begin();
                debug(pos);
                count += max(0, pos - i - 1);
            }
            debug(count);
        }
            cout << endl;
    }
}