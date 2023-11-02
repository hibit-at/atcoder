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
using mint=modint998244353;

int n, m, k;

vector<vector<mint>> dp;

mint dfs(int pos, int sum)
{
    if (sum > k)
    {
        return 0;
    }
    if (pos == n)
    {
        return 1;
    }
    if (dp[pos][sum].val() > -1)
    {
        return dp[pos][sum];
    }
    mint ans = 0;
    rep1(i, m)
    {
        ans += dfs(pos + 1, sum + i);
    }
    return dp[pos][sum] = ans.val();
}

int main(void)
{
    cin >> n >> m >> k;
    dp.resize(n + 1, vector<mint>(k + 1, -1));
    cout << dfs(0, 0).val() << endl;
}