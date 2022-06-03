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
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

template <typename T>
pair<T, int> dfs(const WeightedGraph<T> &g, int idx, int par)
{
    pair<T, int> ret(0, idx);
    for (auto &e : g[idx])
    {
        if (e.to == par)
            continue;
        auto cost = dfs(g, e.to, idx);
        cost.first += e.cost;
        ret = max(ret, cost);
    }
    return ret;
}

template <typename T>
T tree_diameter(const WeightedGraph<T> &g)
{
    auto p = dfs(g, 0, -1);
    auto q = dfs(g, p.second, -1);
    return (q.first);
}

int main(void)
{
    int n;
    cin >> n;
    WeightedGraph<int> graph(n);
    rep(i, n-1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    cout << tree_diameter(graph) + 1 << endl;
}