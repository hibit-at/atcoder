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
    vector<vector<int>> rev(n, vector<int>(0));
    vector<int> graph_out(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        rev[v].push_back(u);
        graph_out[u]++;
    }
    queue<int> q;
    rep(i, n)
    {
        if (graph_out[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        for (int from : rev[now])
        {
            graph_out[from]--;
            if (graph_out[from] == 0)
            {
                q.push(from);
            }
        }
    }
    int ans = 0;
    rep(i, n)
    {
        ans += graph_out[i] > 0;
    }
    cout << ans << endl;
}