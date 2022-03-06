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

const ll mod = 998244353;

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
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(10));
    rep1(i, 9)
    {
        dp[1][i] = 1;
    }
    rep1(i, n - 1)
    {
        rep(j, 10)
        {
            rep(k, 3)
            {
                ll next_dig = j + k - 1;
                if (next_dig < 1 || 10 <= next_dig)
                {
                    continue;
                }
                dp[i + 1][next_dig] += dp[i][j];
                dp[i + 1][next_dig] %= mod;
            }
        }
    }
    // print_vector_vector(dp);
    ll ans = 0;
    rep(i,10){
        ans += dp.back()[i];
        ans %= mod;
    }
    cout << ans << endl;
}