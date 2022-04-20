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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    mint first = 0;
    rep(i, n)
    {
        rep(j, i)
        {
            if (a[j] > a[i])
            {
                first++;
            }
        }
    }
    // debug(first.val());
    rep(i, n)
    {
        a.push_back(a[i]);
    }
    ll second = 0;
    rep(i, 2 * n)
    {
        rep(j, i)
        {
            if (a[j] > a[i])
            {
                second++;
            }
        }
    }
    mint diff = second - 2 * first;
    // debug(diff.val());
    mint ans = 0;
    ans += first * k;
    // debug(ans.val());
    ans += diff * k * (k - 1) / 2;
    // debug(ans.val());
    cout << ans.val() << endl;
}