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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

ll solve(ll n)
{
    vector<ll> digits(64, 0);
    rep(i, 64)
    {
        int j = 63 - i;
        digits[j] = n % 10;
        n /= 10;
    }
    vector<vector<vector<ll>>> dp(65, vector<vector<ll>>(2, vector<ll>(2)));
    dp[0][1][0] = 1; // saturate and not_49
    rep(i, 64)
    {
        // not_saturate
        rep(j, 10)
        {
            bool is_saturate = false;
            bool next_49 = (j == 4 || j == 9);
            dp[i + 1][is_saturate][next_49] += dp[i][is_saturate][false];
            dp[i + 1][is_saturate][true] += dp[i][is_saturate][true];
        }
        // saturate
        rep(j, digits[i] + 1)
        {
            bool next_saturate = (j == digits[i]);
            bool next_49 = (j == 4 || j == 9);
            dp[i + 1][next_saturate][next_49] += dp[i][true][false];
            dp[i + 1][next_saturate][true] += dp[i][true][true];
        }
    }
    ll ans = 0;
    ans += dp[64][true][true] + dp[64][false][true];
    return ans;
}

int main(void)
{
    ll a, b;
    cin >> a >> b;
    a--;
    cout << solve(b) - solve(a) << endl;
}