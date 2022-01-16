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

int main(void)
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll p, q, r, s;
    cin >> p >> q >> r >> s;
    for (ll i = p; i <= q; i++)
    {
        for (ll j = r; j <= s; j++)
        {
            bool sub1 = (i - j) == (a - b);
            bool sub2 = (i + j) == (a + b);
            if (sub1 || sub2)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }
}