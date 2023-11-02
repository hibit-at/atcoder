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

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

bool isOnlyPath(vector<vector<ll>> &wf, int start, int end)
{
    int n = wf.size();
    rep(via, n)
    {
        if (start == via | end == via)
        {
            continue;
        }
        // debug(wf[start][via] + wf[via][end]);
        if (wf[start][via] + wf[via][end] <= wf[start][end])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int n;
    cin >> n;
    const ll inf = 1e18;
    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    vector<vector<ll>> wf(n, vector<ll>(n, inf));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> dp[i][j];
            wf[i][j] = dp[i][j];
        }
    }
    // print_vector_vector(dp);
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                chmin(wf[i][j], wf[i][k] + wf[k][j]);
            }
        }
    }
    // print_vector_vector(wf);
    ll ans = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            if (i >= j)
            {
                continue;
            }
            if (wf[i][j] != dp[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
            if (isOnlyPath(wf, i, j))
            {
                ans += wf[i][j];
            }
        }
    }
    cout << ans << endl;
}