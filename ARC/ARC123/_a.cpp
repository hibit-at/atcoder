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

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = 2 * b - a - c;
    if (x >= 0)
    {
        cout << x << endl;
    }
    else
    {
        x *= -1;
        if (x % 2 == 0)
        {
            cout << x / 2 << endl;
        }
        else
        {
            cout << 1 + (x + 1) / 2 << endl;
        }
    }
}