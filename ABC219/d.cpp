#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const int inf = 2e5;

void chmin(int &a, int b) { a = min(a, b); }

int main(void)
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(x + 1, vector<int>(y + 1, inf)));
    dp[0][0][0] = 0;
    rep(i, n)
    {
        rep(tako, x + 1)
        {
            rep(tai, y + 1)
            {
                int add_tako = a[i];
                int add_tai = b[i];
                int next_tako = tako + add_tako;
                int next_tai = tai + add_tai;
                chmin(next_tako, x);
                chmin(next_tai, y);
                chmin(dp[i + 1][tako + add_tako][tai + add_tai], dp[i][tako][tai] + 1);
                dp[i + 1][tako][tai] = dp[i][tako][tai];
            }
        }
    }
    cout << dp[0][0][0] << endl;
}