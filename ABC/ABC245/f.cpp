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

struct StronglyConnectedComponents
{
    int n;
    vector<vector<int>> G, rG;
    vector<int> order, component;
    vector<bool> used;
    void dfs(int v)
    {
        used[v] = 1;
        for (auto nv : G[v])
        {
            if (!used[nv])
                dfs(nv);
        }
        order.push_back(v);
    }
    void rdfs(int v, int k)
    {
        component[v] = k;
        for (auto nv : rG[v])
        {
            if (component[nv] < 0)
                rdfs(nv, k);
        }
    }

    StronglyConnectedComponents(vector<vector<int>> &_G)
    {
        n = _G.size();
        G = _G;
        rG.resize(n);
        component.assign(n, -1);
        used.resize(n);
        for (int v = 0; v < n; v++)
        {
            for (auto nv : G[v])
                rG[nv].push_back(v);
        }
        for (int v = 0; v < n; v++)
            if (!used[v])
                dfs(v);
        int k = 0;
        reverse(order.begin(), order.end());
        for (auto v : order)
            if (component[v] == -1)
                rdfs(v, k), k++;
    }

    /// 頂点(u, v)が同じ強連結成分に含まれるか
    bool is_same(int u, int v) { return component[u] == component[v]; }

    /// 強連結成分を1つのノードに潰したグラフを再構築する
    vector<vector<int>> rebuild()
    {
        int N = *max_element(component.begin(), component.end()) + 1;
        vector<vector<int>> rebuildedG(N);
        set<pair<int, int>> connected;
        for (int v = 0; v < N; v++)
        {
            for (auto nv : G[v])
            {
                if (component[v] != component[nv] and !connected.count(make_pair(v, nv)))
                {
                    connected.insert(make_pair(v, nv));
                    rebuildedG[component[v]].push_back(component[nv]);
                }
            }
        }
        return rebuildedG;
    }
};

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n, vector<int>());
    vector<int> jis(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
        jis[v]++;
    }
    StronglyConnectedComponents scc = StronglyConnectedComponents(to);
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    print_vector(scc.order);
    print_vector(scc.component);
    print_vector(jis);
}