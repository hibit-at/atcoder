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
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

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

const ll mod = 1e9 + 7;

int main(void)
{
    ll n, b, k;
    cin >> n >> b >> k;
    vector<ll> c(k);
    rep(i, k)
    {
        cin >> c[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(b));
    vector<ll> mod10(n);
    mod10[0] = 1;
    rep(i, n - 1)
    {
        mod10[i + 1] = mod10[i] * 10;
        mod10[i + 1] %= b;
    }
    // print_vector(mod10);
    dp[0][0] = 1;
    rep(i, n)
    {
        rep(j, b)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }
            rep(p, k)
            {
                ll next = j + c[p] * mod10[i];
                next %= b;
                dp[i + 1][next] += dp[i][j];
                dp[i + 1][next] %= mod;
            }
        }
    }
    // print_vector(c);
    // print_vector_vector(dp);
    cout << dp.back().front() << endl;
}