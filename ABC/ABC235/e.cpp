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

int main(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<pair<int, int>, pair<int, int>>> edge(0);
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge.push_back({{c, -1}, {a, b}});
    }
    vector<bool> ans(q, false);
    rep(i, q)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edge.push_back({{w, i}, {u, v}});
    }
    sort(all(edge));
    dsu uf(n);
    for (auto e : edge)
    {
        int cost = e.first.first;
        int query = e.first.second;
        int sub_e1 = e.second.first;
        int sub_e2 = e.second.second;
        // debug(cost);
        // debug(query);
        // debug(sub_e1);
        // debug(sub_e2);
        if (query > -1)
        {
            if (!uf.same(sub_e1, sub_e2))
            {
                ans[query] = true;
            }
            else
            {
                ans[query] = false;
            }
        }
        else
        {
            if (!uf.same(sub_e1, sub_e2))
            {
                uf.merge(sub_e1, sub_e2);
            }
        }
    }
    for (bool b : ans)
    {
        if (b)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}