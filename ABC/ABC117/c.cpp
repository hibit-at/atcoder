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
    int n, m;
    cin >> n >> m;
    vector<ll> x(m);
    rep(i, m)
    {
        cin >> x[i];
    }
    sort(all(x));
    vector<ll> y(m - 1);
    rep(i, m - 1)
    {
        y[i] = x[i + 1] - x[i];
    }
    // print_vector(y);
    sort(all(y));
    if (m - n < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << accumulate(y.begin(), y.begin() + m - n, 0LL);
}