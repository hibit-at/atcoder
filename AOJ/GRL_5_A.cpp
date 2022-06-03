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

auto chmax = [](auto &a, auto b)
{ a = max(a, b); };

int n;
vector<vector<pair<int, int>>> to;
map<pair<int, int>, int> dp;

int dfs(int now, int parent)
{
    // debug(now);
    if (dp[{now, parent}] > 0)
    {
        return dp[{now, parent}];
    }
    int ans = 0;
    for (pair<int, int> edge : to[now])
    {
        int next = edge.first;
        if (next == parent)
        {
            continue;
        }
        int cost = edge.second;
        chmax(ans, cost + dfs(next, now));
    }
    return dp[{now, parent}] = ans;
}

int main(void)
{
    cin >> n;
    to.resize(n, vector<pair<int, int>>(0));
    rep(i, n - 1)
    {
        int s, t, w;
        cin >> s >> t >> w;
        to[s].push_back({t, w});
        to[t].push_back({s, w});
    }
    auto print_to = [](auto v)
    {
        for (auto i : v)
        {
            auto print_vector_pair = [](auto v)
            {
                for (auto i : v)
                {
                    cout << "(" << i.first << "," << i.second << ")"
                         << " ";
                }
                cout << endl;
            };
            print_vector_pair(i);
        }
        cout << endl;
    };
    // print_to(to);
    int ans = 0;
    rep(i, n)
    {
        chmax(ans, dfs(i, i));
    }
    cout << ans << endl;
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    // print_vector_vector(dp);
}