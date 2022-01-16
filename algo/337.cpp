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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

const int inf = 1e9;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i, n)
    {
        cin >> w[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(m + 1, false));
    dp[0][0] = true;
    dp[0][w[0]] = true;
    rep(i, n)
    {
        rep(j, m + 1)
        {
            if (i + 1 < n)
            {
                bool tmp = dp[i + 1][j] || dp[i][j];
                dp[i + 1][j] = tmp;
            }
            if (i + 1 < n && j + w[i + 1] <= m)
            {
                bool tmp = dp[i + 1][j + w[i + 1]] || dp[i][j];
                dp[i + 1][j + w[i + 1]] = tmp;
            }
        }
    }
    if (dp.back()[m])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}