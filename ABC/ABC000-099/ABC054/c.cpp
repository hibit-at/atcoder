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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n, vector<int>());
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    const int inf = 1e9;
    vector<vector<int>> dp(1 << n, vector<int>(n, inf));
    vector<bool> seen(n);
    dp[0][0] = 1;
    rep(i, 1 << n)
    {
        rep(j, n)
        {
            for (int next : to[j])
            {
                debug(next);
            }
        }
    }
}