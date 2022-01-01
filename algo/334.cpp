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
void chmax(T &a, T b) { a = max(a, b); }

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = a[0][0];
    rep(i, n)
    {
        rep(j, n)
        {
            if (i + 1 < n)
            {
                chmax(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            }
            if (j + 1 < n)
            {
                chmax(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
            }
        }
    }
    cout << dp.back().back() << endl;
}