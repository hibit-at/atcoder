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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint;

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();
    mint::set_mod(13);
    mint factor = 1;
    vector<vector<modint1000000007>> dp(n + 1, vector<modint1000000007>(13, 0));
    dp[0][0] = 1;
    reverse(all(s));
    rep(i, n)
    {
        rep(now_mod, 13)
        {
            if (s[i] == '?')
            {
                for (mint next_num = 0; next_num.val() < 10; next_num++)
                {
                    mint next_mod = next_num * factor + now_mod;
                    dp[i + 1][next_mod.val()] += dp[i][now_mod];
                }
            }
            else
            {
                mint next_num = s[i] - '0';
                mint next_mod = next_num * factor + now_mod;
                dp[i + 1][next_mod.val()] += dp[i][now_mod];
            }
        }
        factor *= 10;
    }
    cout << dp[n][5].val() << endl;
}