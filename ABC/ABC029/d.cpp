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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> digits(10, 0);
    rep(i, 10)
    {
        int j = 9 - i;
        digits[j] = n % 10;
        n /= 10;
    }
    // print_vector(digits);
    vector<vector<vector<ll>>> dp(11, vector<vector<ll>>(2, vector<ll>(10)));
    dp[0][1][0] = 1; //飽和していて、1が0個
    rep(i, 10)
    {
        rep(now_saturate, 2)
        {
            rep(j, 10) //次の数
            {
                if (now_saturate & j > digits[i])
                {
                    continue;
                }
                bool next_saturate = now_saturate & (j == digits[i]);
                rep(k, 10) //累計何個
                {
                    int next_one = (j == 1);
                    dp[i + 1][next_saturate][k + next_one] += dp[i][now_saturate][k];
                }
            }
        }
    }
    ll ans = 0;
    rep(i, 10)
    {
        ans += (dp[10][true][i] + dp[10][false][i]) * i;
    }
    cout << ans << endl;
}