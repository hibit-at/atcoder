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

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n - 1);
    cin >> a;
    vector<vector<mint>> dp(100, vector<mint>(n + 1));
    dp[0][0] = 1;
    rep(i, 99)
    {
        rep(j, n)
        {
            dp[i + 1][j] += dp[i][j] / (a[j] + 1);
            dp[i + 1][min(j + a[j], n)] -= dp[i][j] / (a[j] + 1);
        }
    }
    rep(i, 100)
    {
        rep(j, n + 1)
        {
            cout << dp[i][j].val() << " ";
        }
        cout << endl;
    }
}