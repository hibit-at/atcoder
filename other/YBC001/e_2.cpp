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
void chmax(T &a, T b) { a = max(a, b); }
template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(m);
    rep(i, m)
    {
        cin >> a[i];
    }
    sort(all(a));
    vector<ll> factor(n + 1);
    factor[0] = 1;
    rep(i, n)
    {
        factor[i + 1] = (factor[i] * 10) % k;
    }
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(2, vector<bool>(k)));
    dp[0][1][0] = 1; // 全て0か？
    int ans = -1;
    rep(i, n)
    {
        rep(all_zero, 2)
        {
            rep(now_mod, k)
            {
                for (int next_num : a)
                {
                    bool next_all_zero = (next_num == 0) & all_zero;
                    if (dp[i][all_zero][now_mod])
                    {
                        dp[i + 1][next_all_zero][(now_mod + next_num * factor[i]) % k] = true;
                    };
                    if (dp[i + 1][0][0])
                    {
                        chmax(ans, i + 1);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}