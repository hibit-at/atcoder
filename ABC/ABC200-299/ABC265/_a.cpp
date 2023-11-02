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
#define int ll
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n - 1);
    cin >> a;
    vector<int> bonus(n);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        bonus[x] = y;
    }
    rep(i, n)
    {
        t += bonus[i];
        if (t <= a[i])
        {
            cout << "No" << endl;
            return 0;
        }
        else
        {
            t -= a[i];
        }
    }
    cout << "Yes" << endl;
}