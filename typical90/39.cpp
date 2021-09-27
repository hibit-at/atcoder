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
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

vector<ll> dp;
vector<vector<int>> to;

void print_to(vector<vector<int>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : to ";
        for (int next : to[i])
        {
            cout << next << ",";
        }
        cout << endl;
    }
}

void tree_dp(int pos, int pre)
{
    dp[pos] = 1;
    for (int next : to[pos])
    {
        if (next == pre)
        {
            continue;
        }
        tree_dp(next, pos);
        dp[pos] += dp[next];
    }
}

int main(void)
{
    int n;
    cin >> n;
    to.resize(n + 1);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // print_to(to);
    dp.resize(n + 1, -1);
    tree_dp(1, -1);
    ll ans = 0;
    rep1(i, n)
    {
        ans += dp[i] * (n - dp[i]);
    }
    cout << ans << endl;
}