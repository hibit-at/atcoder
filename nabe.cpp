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

void solve(ll n)
{
    vector<int> dig(18);
    rep(i, 18)
    {
        int rev_i = 17 - i;
        dig[rev_i] = n % 10;
        n /= 10;
    }
    vector<vector<vector<vector<ll>>>> dp(19, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(3))));
    dp[0][1][0][0] = 1;
    rep(i, 18)
    {
        rep(saturate, 2)
        {
            rep(nabe, 2)
            {
                rep(mod3, 3)
                {
                    rep(next_num, 10)
                    {
                        if (next_num > dig[i] && saturate)
                        {
                            continue;
                        }
                        bool next_saturate = saturate & (next_num == dig[i]);
                        bool next_nabe = nabe || (next_num == 3);
                        int next_mod3 = (mod3 + next_num) % 3;
                        dp[i + 1][next_saturate][next_nabe][next_mod3] += dp[i][saturate][nabe][mod3];
                    }
                }
            }
        }
    }
    ll ans = -1;
    rep(saturate, 2)
    {
        rep(nabe, 2)
        {
            rep(mod3, 3)
            {
                if (!nabe && mod3)
                {
                    continue;
                }
                ans += dp[18][saturate][nabe][mod3];
            }
        }
    }
    debug(ans);
}

int main(void)
{
    ll n;
    cin >> n;
    solve(n);
}