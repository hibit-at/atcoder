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
    vector<vector<int>> dp(4, vector<int>(4));
    rep(j, 4)
    {
        cin >> dp[0][j];
    }
    rep(i, 3)
    {
        rep(j, 4)
        {
            rep(k,3){
                int step = k-1;
                int next = j+step;
                if(next >= 0 && next <4){
                    dp[i+1][next] += dp[i][j];
                }
            }
        }
    }
    cout << dp[3][3] << endl;
}