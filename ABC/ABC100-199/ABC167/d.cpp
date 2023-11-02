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
    vector<vector<ll>> dp(64, vector<ll>(n, 0));
    rep(i, n)
    {
        cin >> dp[0][i];
        dp[0][i]--;
    }
    rep(i, 63)
    {
        rep(j, n)
        {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
    int ans = 0;
    for (int i = 63; i >= 0; i--)
    {
        bool bit = (k >> i) & 1;
        if (bit)
        {
            ans = dp[i][ans];
        }
    }
    cout << ans + 1 << endl;
}