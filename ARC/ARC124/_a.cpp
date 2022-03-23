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
using mint = modint998244353;

int main(void)
{
    int n, K;
    cin >> n >> K;
    vector<mint> dp(n);
    vector<bool> free(n, true);
    rep(i, K)
    {
        char c;
        int k;
        cin >> c >> k;
        k--;
        free[k] = false;
        rep(j, n)
        {
            if (c == 'R' && j <= k)
            {
                dp[j]++;
            }
            if (c == 'L' && k <= j)
            {
                dp[j]++;
            }
        }
    }
    mint ans = 1;
    rep(i, n)
    {
        if (free[i])
        {
            ans *= dp[i];
        }
    }
    cout << ans.val() << endl;
}