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
    scc_graph graph(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.add_edge(u, v);
        rev[v].push_back(u);
    }
    auto scc = graph.scc();
    vector<bool> check(n);
    for (auto v : scc)
    {
        if (v.size() == 1)
        {
            continue;
        }
        for (int now : v)
        {
            queue<int> q;
            q.push(now);
            while (q.size() > 0)
            {
                int front = q.front();
                q.pop();
                check[front] = true;
                for (int from : rev[front])
                {
                    if (check[from])
                    {
                        continue;
                    }
                    q.push(from);
                }
            }
        }
    }
    cout << accumulate(all(check), 0) << endl;
}