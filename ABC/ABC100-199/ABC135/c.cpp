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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    ll limit = 0;
    rep(i, n + 1)
    {
        cin >> a[i];
        limit += a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    ll ans = limit;
    rep(i, n)
    {
        a[i] -= b[i];
        if (a[i] < 0)
        {
            a[i + 1] = max(a[i + 1] + a[i], 0LL);
            a[i] = 0;
        }
        // print_vector(a);
    }
    rep(i, n+1)
    {
        ans -= a[i];
    }
    cout << ans << endl;
}