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
void chmin(T &a, T b) { a = min(a, b); }

const int inf = 2e9;

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            if (i == inf)
            {
                cout << '-' << ',';
            }
            else
            {
                cout << i << ',';
            }
        }
        cout << endl;
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n + 1, vector<int>());
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, inf));
    queue<pair<int, int>> q;
    rep(i, n)
    {
        dp[1 << i][i] = 1;
        q.push({1 << i, i});
    }
    while (q.size())
    {
        print_vector_vector(dp);
        cout << endl;
        int state = q.front().first;
        int now = q.front().second;
        q.pop();
        for (int next : to[now])
        {
            int next_state = state ^ (1 << next);
            if (dp[next_state][next] < inf)
            {
                continue;
            }
            dp[next_state][next] = dp[state][now] + 1;
            q.push({next_state, next});
        }
    }
    rep(i, n)
    {
        dp[0][i] = 0;
    }
    ll ans = 0;
    rep(i, 1 << n)
    {
        int tmp = inf;
        rep(j, n)
        {
            chmin(tmp, dp[i][j]);
        }
        ans += tmp;
    }
    cout << ans << endl;
}