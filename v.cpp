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

#include <atcoder/dsu>
using namespace atcoder;

int n, m;
vector<vector<int>> to;
vector<ll> dp;
vector<ll> sell;
vector<ll> a;

const ll inf = 1e18;
template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

ll dfs(int now)
{
    if (dp[now] > -inf)
    {
        return dp[now];
    }
    for (int next : to[now])
    {
        chmax(sell[now], dfs(next));
    }
    return dp[now] = max(a[now], sell[now]);
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

int main()
{
    cin >> n >> m;
    a.resize(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    // print_vector(a);
    to.resize(n, vector<int>());
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        to[x].push_back(y);
    }
    dp.resize(n, -inf);
    sell.resize(n, -inf);
    rep(i, n)
    {
        dfs(i);
    }
    // print_vector(dp);
    ll ans = -inf;
    rep(i, n)
    {
        if (to[i].size() == 0)
        {
            continue;
        }
        chmax(ans, sell[i] - a[i]);
    }
    cout << ans << endl;
}