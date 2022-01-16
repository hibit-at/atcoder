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

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    int x, y;
    cin >> x >> y;
    a[0] = x;
    a[1] = y;
    rep(i, n - 2)
    {
        a[i + 2] = a[i + 1] + a[i];
        a[i + 2] %= 100;
    }
    cout << a.back() << endl;
}