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

int main(void)
{
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    ll last = a + d * (n - 1);
    // debug(a);
    // debug(last);
    ll top = max(a, last);
    ll bottom = min(a, last);
    if (top <= x)
    {
        cout << x - top << endl;
    }
    else if (x <= bottom)
    {
        cout << bottom - x << endl;
    }
    else
    {
        x -= a;
        x %= abs(d);
        x += abs(d);
        x %= abs(d);
        // debug(x);
        cout << min(abs(d) - x, x) << endl;
    }
}