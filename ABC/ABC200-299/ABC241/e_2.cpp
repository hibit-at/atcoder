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
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(40, vector<ll>(n));
    rep(i, n)
    {
        cin >> dp[0][i];
    }
    rep(i, 39)
    {
        rep(j, n)
        {
            dp[i + 1][j] = dp[i][j] + dp[i][(j + dp[i][j]) % n];
        }
    }
    ll ans = 0;
    rep(i, 40)
    {
        if (k & 1)
        {
            ans += dp[i][ans % n];
        }
        k /= 2;
    }
    // print_vector_vector(dp);
    cout << ans << endl;
    return 0;
}