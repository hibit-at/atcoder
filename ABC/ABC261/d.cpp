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
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    cin >> x;
    vector<ll> c(m), y(m);
    vector<ll> bonus(n + 1);
    rep(i, m)
    {
        cin >> c[i] >> y[i];
        bonus[c[i]] = y[i];
    }
    auto print_vector = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    // print_vector(bonus);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    dp[0][0] = 0;
    rep(i, n)
    {
        rep(j, n + 1)
        {
            if (dp[i][j] == -1)
            {
                continue;
            }
            auto chmax = [](auto &a, auto b)
            { a = max(a, b); };
            chmax(dp[i + 1][0], dp[i][j]);
            chmax(dp[i + 1][j + 1], dp[i][j] + x[i] + bonus[j + 1]);
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
    // print_vector_vector(dp);
    ll ans = 0;
    rep(j, n + 1)
    {
        auto chmax = [](auto &a, auto b)
        { a = max(a, b); };
        chmax(ans, dp[n][j]);
    }
    cout << ans << endl;
}