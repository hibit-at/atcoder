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

vector<vector<int>> to;
vector<vector<mint>> dp;
vector<vector<bool>> seen;

mint dfs(int now, int from, bool black)
{
    if (seen[now][black])
    {
        return dp[now][black];
    }
    mint ans = 1;
    for (int next : to[now])
    {
        if (next == from)
        {
            continue;
        }
        mint tmp = 0;
        tmp += dfs(next, now, 0);
        if (!black)
        {
            tmp += dfs(next, now, 1);
        }
        ans *= tmp;
    }
    seen[now][black] = true;
    return dp[now][black] = ans;
}

int main(void)
{
    int n;
    cin >> n;
    dp.resize(n + 1, vector<mint>(2, -1));
    to.resize(n + 1, vector<int>(0));
    seen.resize(n + 1, vector<bool>(2,false));
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    cout << (dfs(1, 0, 0) + dfs(1, 0, 1)).val() << endl;
}