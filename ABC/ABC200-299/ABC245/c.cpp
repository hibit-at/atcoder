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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(2));
    dp[0][1] = 1;
    dp[0][0] = 1;
    rep(i, n - 1)
    {
        if (dp[i][0])
        {
            if (abs(a[i] - a[i + 1]) <= k)
            {
                dp[i + 1][0] = true;
            }
            if (abs(a[i] - b[i + 1]) <= k)
            {
                dp[i + 1][1] = true;
            }
        }
        if (dp[i][1])
        {
            if (abs(b[i] - a[i + 1]) <= k)
            {
                dp[i + 1][0] = true;
            }
            if (abs(b[i] - b[i + 1]) <= k)
            {
                dp[i + 1][1] = true;
            }
        }
    }
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    if (dp[n - 1][0] || dp[n - 1][1])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}