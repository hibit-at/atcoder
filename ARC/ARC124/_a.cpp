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
    vector<mint> dp(n, K);
    rep(i, K)
    {
        char c;
        int k;
        cin >> c >> k;
        k--;
        dp[k] = 1;
        if (c == 'L')
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[j]--;
                if (dp[j].val() < 1)
                {
                    dp[j] = 1;
                }
            }
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                dp[j]--;
                if (dp[j].val() < 1)
                {
                    dp[j] = 1;
                }
            }
        }
    }
    // rep(i, n)
    // {
    //     cout << dp[i].val() << ',';
    // }
    mint ans = 1;
    rep(i, n)
    {
        ans *= dp[i];
    }
    cout << ans.val() << endl;
}