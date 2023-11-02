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

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;
    rep(i, n - 1)
    {
        rep(j, n)
        {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j + 1] += dp[i][j];
        }
    }
    auto print_join = [](auto v,int m)
    {
        int size = v.size();
        rep(i, m)
        {
            if (i < m - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    rep(i, n)
    {
        print_join(dp[i], i+1);
    }
}