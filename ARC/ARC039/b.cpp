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
    ll n, k;
    cin >> n >> k;
    vector<mint> fact(2 * n, 1);
    rep(i, 2 * n - 1)
    {
        fact[i + 1] = fact[i] * (i + 1);
    }
    if (n > k)
    {
        ll h = n + k - 1;
        cout << (fact[h] / fact[k] / fact[h-k]).val() << endl;
    }
    else
    {
        k %= n;
        cout << (fact[n] / fact[k] / fact[n - k]).val() << endl;
    }
}