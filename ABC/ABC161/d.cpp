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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

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

int length(ll n)
{
    int ans = 0;
    while (n)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

ll lunlun(ll mid)
{
    mid = 21;
    int size = length(mid);
    vector<ll> digits(size);
    rep(i, size)
    {
        int j = size - 1 - i;
        digits[j] = mid % 10;
        mid /= 10;
    }
    print_vector(digits);
    vector<vector<vector<ll>>> dp(size + 1, vector<vector<ll>>(2, vector<ll>(10)));
    dp[0][1][0] = 1;
    rep(i, size)
    {
        rep(saturate, 2)
        {
            rep(now_num, 10)
            {
                rep(d, 3)
                {
                    int next_num = now_num + d - 1;
                    if (next_num < 0 || 10 <= next_num)
                    {
                        continue;
                    }
                    if ((next_num > digits[i + 1]) && saturate)
                    {
                        continue;
                    }
                    bool next_saturate = (next_num == digits[i + 1]) && saturate;
                    dp[i + 1][next_saturate][next_num] += dp[i][saturate][now_num];
                }
            }
        }
    }
    rep(i, size)
    {
        rep(j, 10)
        {
            cout << dp[i][0][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
    rep(i, size)
    {
        rep(j, 10)
        {
            cout << dp[i][1][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
    ll ans = 0;
    rep(saturate, 2)
    {
        rep(now_num, 10)
        {
            ans += dp.back()[saturate][now_num];
        }
    }
    debug(ans);
    return ans;
}

bool solve(ll mid, int k)
{
    if (lunlun(mid) >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    ll k;
    cin >> k;
    ll ng = -1;
    ll ok = 1e18;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (solve(mid, k))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}