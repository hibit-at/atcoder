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

const int inf = 1e9;

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));
    rep(j, n)
    {
        cin >> dp[0][j];
    }
    rep(i, n-1)
    {
        rep(j, n)
        {
            rep(k,3){
                int step = k-1;
                int next = j+step;
                if(next >= 0 && next <n){
                    dp[i+1][next] += dp[i][j];
                    dp[i+1][next] %= 100;
                }
            }
        }
    }
    cout << dp.back().back() << endl;
}