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
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n)
    {
        cin >> w[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(1e6, false));
    int mid = 5 * 1e5;
    dp[0][mid] = 1;
    rep(i, n)
    {
        rep(j, 1e6)
        {
            if (dp[i][j] == false)
            {
                continue;
            }
            int next = j - w[i];
            if (i + 1 <= n && next >= 0)
            {
                dp[i + 1][next] = true;
            }
            next = j + w[i];
            if (i + 1 <= n && next < 1e6)
            {
                dp[i + 1][next] = true;
            }
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, 1e6)
    {
        if (dp[n][i])
        {
            q.push(abs(i - mid));
        }
    }
    cout << q.top() << endl;
}