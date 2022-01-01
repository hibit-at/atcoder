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
void chmin(T &a, T b) { a = min(a, b); }

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    rep(i, n)
    {
        cin >> x[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(a, false));
    dp.front().front() = true;
    rep(i, n)
    {
        rep(j, a)
        {
            if (dp[i][j] == false)
            {
                continue;
            }
            if (i + 1 <= n)
            {
                dp[i + 1][j] = true;
            }
            int next = j + x[i];
            next %= a;
            if (i + 1 <= n && next < a)
            {
                dp[i + 1][next] = true;
            }
        }
    }
    if (dp.back()[b])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}