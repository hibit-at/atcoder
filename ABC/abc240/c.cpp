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
    int n, x;
    cin >> n >> x;
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    dp[0][0] = true;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    rep(i, n)
    {
        rep(j, x + 1)
        {
            if (!dp[i][j])
            {
                continue;
            }
            if (j + a[i] <= x)
            {
                dp[i + 1][j + a[i]] = true;
            }
            if (j + b[i] <= x)
            {
                dp[i + 1][j + b[i]] = true;
            }
        }
    }
    // print_vector_vector(dp);
    if (dp[n][x])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}