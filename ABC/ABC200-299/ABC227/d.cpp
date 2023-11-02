#include <algorithm>
#include <iostream>
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
    ll ok = -1;
    ll ng = ll(1e18) + 1;
    while (abs(ok - ng) > 1)
    // for (ll target = 1; target < 10; target++)
    {
        // ll target = 2;
        ll target = ok + ng;
        target /= 2;
        ll sum = 0;
        rep(i, n)
        {
            sum += min(a[i], target);
        }
        // debug(target * k);
        // debug(sum);
        if (target <= sum / k)
        {
            // cout << "ok" << endl;
            ok = target;
        }
        else
        {
            // cout << "ng" << endl;
            ng = target;
        }
    }
    cout << ok << endl;
}