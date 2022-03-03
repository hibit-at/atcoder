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
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
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

int n, q;
vector<ll> x;
vector<vector<int>> to;
vector<vector<ll>> dp;
vector<bool> seen;

void solve(int v, int k)
{
    return;
}

vector<ll> dfs(int now)
{
    seen[now] = true;
    vector<ll> ans;
    ans.push_back(x[now]);
    for (int next : to[now])
    {
        if (seen[next])
        {
            continue;
        }
        vector<ll> next_vector;
        if (dp[next].size() > 0)
        {
            next_vector = dp[next];
        }
        else
        {
            next_vector = dfs(next);
        }
        for (ll elem : next_vector)
        {
            ans.push_back(elem);
        }
        sort(all(ans));
        reverse(all(ans));
        if (ans.size() >= 20)
        {
            rep(i, ans.size() - 20)
            {
                ans.pop_back();
            }
        }
    }
    return dp[now] = ans;
}

int main(void)
{
    cin >> n >> q;
    // define x
    x.resize(n + 1);
    rep1(i, n)
    {
        cin >> x[i];
    }
    // define to
    to.resize(n + 1, vector<int>());
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // dfs
    dp.resize(n + 1, {});
    seen.resize(n + 1, false);
    dfs(1);
    // solve
    rep(i, q)
    {
        int v, k;
        cin >> v >> k;
        cout << dp[v][k - 1] << endl;
    }
}