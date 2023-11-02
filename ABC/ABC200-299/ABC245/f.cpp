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

#include <atcoder/scc>
using namespace atcoder;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n, vector<int>(0));
    scc_graph graph(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.add_edge(u, v);
        to[u].push_back(v);
    }
    auto scc = graph.scc();
    int k = scc.size();
    vector<int> idx(n);
    rep(i, k)
    {
        for (auto v : scc[i])
        {
            idx[v] = i;
        }
    }
    vector<int> dp(k, 0);
    for (int i = k - 1; i >= 0; i--)
    {
        if (scc[i].size() == 1)
        {
            int from = scc[i][0];
            for (auto next : to[from])
            {
                dp[i] |= dp[idx[next]];
            }
        }
        else
        {
            dp[i] = 1;
        }
    }
    int ans = 0;
    rep(i, k)
    {
        if (dp[i])
        {
            ans += scc[i].size();
        }
    }
    cout << ans << endl;
}