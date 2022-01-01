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
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1), b(n - 1);
    rep(i, n - 1)
    {
        cin >> a[i];
    }
    rep(i, n - 1)
    {
        cin >> b[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp.front().front() = 0;
    rep(i, n - 1)
    {
        rep(j, m + 1)
        {
            if (dp[i][j] == -1)
            {
                continue;
            }
            if (i + 1 <= n)
            {
                chmax(dp[i + 1][j], dp[i][j]);
            }
            int next = j + a[i];
            if (i + 1 <= n && next < m)
            {
                chmax(dp[i + 1][next], dp[i][j] + b[i]);
            }
        }
    }
    cout << dp.back().back() << endl;
}