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
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(16, vector<ll>(16, 0));
    dp[0][0] = 1;
    rep(i, 15)
    {
        rep(j, 16)
        {
            dp[i + 1][j] += dp[i][j];
            if (j + 1 < 16)
            {
                dp[i + 1][j + 1] += dp[i][j];
            }
        }
    }
    k += n;
    if (k % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << dp[n][k / 2] << endl;
}