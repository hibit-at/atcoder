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

int main(void)
{
    int w;
    int n, K;
    cin >> w >> n >> K;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(K + 1)));
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    rep(i, n + 1)
    {
        rep(j, w + 1)
        {
            rep(k, K + 1)
            {
                if (i + 1 <= n)
                {
                    chmax(dp[i + 1][j][k], dp[i][j][k]);
                }
                if (k + 1 <= K)
                {
                    chmax(dp[i][j][k + 1], dp[i][j][k]);
                }
                if (j + a[i] > w)
                {
                    continue;
                }
                if (i + 1 <= n && k + 1 <= K)
                {
                    chmax(dp[i + 1][j + a[i]][k + 1], dp[i][j][k] + b[i]);
                }
            }
        }
    }
    cout << dp[n][w][K] << endl;
}