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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;

int main(void)
{
    ll x, y;
    cin >> x >> y;
    if ((x + y) % 3 > 0 || 2 * x < y || 2 * y < x)
    {
        cout << 0 << endl;
        return 0;
    }
    mint a = (2 * x - y) / 3;
    mint b = (-x + 2 * y) / 3;
    mint c = a + b;
    vector<mint> fact(c.val() + 1, 1);
    rep(i, c.val())
    {
        fact[i + 1] = fact[i] * (i + 1);
    }
    mint ans = fact[c.val()];
    ans /= fact[a.val()];
    ans /= fact[b.val()];
    cout << ans.val() << endl;
}