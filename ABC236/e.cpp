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
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    int n;
    cin >> n;
    vector<double> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<pair<double, int>> dp(n);
    dp[0] = {a[0], 1};
    if (a[1] > (a[0] + a[1]) / 2)
    {
        dp[1] = {a[1], 1};
    }
    else
    {
        dp[1] = {(a[0] + a[1]) / 2, 2};
    }
    rep(i, n)
    {
        double now_sum = dp[i].first * dp[i].second;
        int next = i + 1;
        if (next >= n)
        {
            continue;
        }
        // if next
        double next_sum = now_sum + a[next];
        double next_mean = next_sum / (dp[i].second + 1);
        if (next_mean > dp[next].first)
        {
            dp[next] = {next_mean, dp[i].second + 1};
        }
        // if skip
        int skip = i + 2;
        if (skip >= n)
        {
            continue;
        }
        double skip_sum = now_sum + a[skip];
        double skip_mean = skip_sum / (dp[i].second + 1);
        if (skip_mean > dp[skip].first)
        {
            dp[skip] = {skip_mean, dp[i].second + 1};
        }
    }
    rep(i, n)
    {
        debug(dp[i].first);
        debug(dp[i].second);
    }
}