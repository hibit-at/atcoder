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
const int inf = 2e9;

int main(void)
{
    int n;
    ll max_w;
    cin >> n >> max_w;
    vector<ll> w(n);
    vector<int> v(n);
    rep(i, n)
    {
        cin >> w[i] >> v[i];
    }
    int max_v = accumulate(all(v), 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(max_v + 1, inf));
    dp[0][0] = 0;
    rep(i, n)
    {
        rep(now_val, max_v + 1)
        {
            auto chmin = [](auto &a, auto b)
            { a = min(a, b); };
            chmin(dp[i + 1][now_val], dp[i][now_val]);
            int next_val = now_val + v[i];
            if (next_val <= max_v)
            {
                chmin(dp[i + 1][next_val], dp[i][now_val] + w[i]);
            }
        }
    }
    int pos = max_v;
    while (dp[n][pos] > max_w)
    {
        pos--;
    }
    cout << pos << endl;
}